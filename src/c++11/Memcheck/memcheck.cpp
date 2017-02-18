//
//  memcheck.cpp
//  Memcheck
//
//  Created by Sunil on 2/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//
#include <mutex>
#include <string>  
#include <cstddef> 

#include "memcheck.h"

#ifdef new
#undef new
#endif

#ifdef delete
#undef delete
#endif

shared_ptr<Memcheck> Memcheck::memcheck(new Memcheck);

bool& selfCall() {
    static bool self = false;
    return self;
}

void* operator new(size_t block, const char *filename, int line) {
    auto tracker = Memcheck::Instance();
    if(selfCall() || tracker == nullptr) {
        return malloc(block);
    } else {
        auto address = malloc(block);
        try {
            selfCall() = true;
            tracker->Track(address, block, filename, line);
            selfCall() = false;
            return address;
        } catch (...) {
            // no except
        }
        return address;
    }
}

void* operator new[](size_t block, const char *filename, int line) {
    return operator new(block, filename, line);
}

void deletep(const char *filename, int line) {
    file = filename;
    pline = line;
}

void operator delete(void *address) noexcept {
    try {
        auto tracker = Memcheck::Instance();
        if(selfCall() || tracker == nullptr) {
            free(address);
            return;
        }
        
        selfCall() = true;
        free(address);
        tracker->UnTrack(address);
        selfCall() = false;
    } catch(...) {
        // no exception
    }
}

void operator delete[](void *address) noexcept {
    operator delete(address);
}

shared_ptr<Memcheck> Memcheck::Instance() {
    return Memcheck::memcheck;
}

void Memcheck::Debug(void *address, const char* file, int line) {
    cout << address << " Alloc'd in file: " << file << " at line: " << line << endl;
}

void Memcheck::Track(void *address, size_t block, const char* file, int line) {
    std::string str(file);
    std::size_t found = str.find_last_of("/\\");
    cout << "Alloc'd " << str.substr(found+1) << ":" << line << " size: " << block << " blocks" << endl;
    
    MemChunk chunk {
        .address = address,
        .size = block,
        .file = std::string(file),
        .line = line
    };
    
    chunks.push_back(std::move(chunk));
}

void Memcheck::UnTrack(void *address) {
    auto chunk = std::find_if(std::begin(chunks), std::end(chunks), [=](MemChunk& e) -> bool {
        if (e.address == address) {
            std::size_t found = e.file.find_last_of("/\\");
            cout << "Dalloc'd " << e.file.substr(found+1) << ":" << e.line << " size: "
                 << e.size << " blocks" << endl;
            
        }
        return e.address == address;
    });
    
    if (chunk == std::end(chunks)) {
        return;
    }
    
    chunks.erase(chunk);
}

Memcheck::~Memcheck() {
    if(chunks.size() > 0) {
        cout << "======================" << endl;
        cout << "Memory leaks!" << endl;
        int total = 0;
        for(auto& e : chunks) {
            std::size_t found = e.file.find_last_of("/\\");
            cout << "Alloc'd " << e.file.substr(found+1) << " : " << e.line << " size: " << e.size
                 << " blocks" << endl;
            total += e.size;
        }
        cout << "Total leak: " << total << " blocks" << endl;
        cout << "======================" << endl;
    }
    cout << "Destroying Memcheck" << endl;
    memcheck = nullptr;
}

Memcheck::Memcheck() {
    cout << "Initializing Memcheck" << endl;
}
