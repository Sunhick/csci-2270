//
//  memcheck.cpp
//  Memcheck
//
//  Created by Sunil on 2/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//
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

// Don't track self calls.
bool& selfCall() {
    static bool self = false;
    return self;
}

void* operator new(size_t block, const char *filename, const char *func, int line) {
    auto tracker = Memcheck::Instance();
    if(selfCall() || tracker == nullptr) {
        // No need to call constructor. Since we are only overloading the allocation part of new.
        // http://stackoverflow.com/questions/31106449/why-overloaded-new-operator-is-calling-constructor-even-i-am-using-malloc-inside
        return malloc(block);
    } else {
        auto address = malloc(block);
        try {
            selfCall() = true;
            tracker->Track(address, block, filename, func, line);
            selfCall() = false;
            return address;
        } catch (...) {
            // no except
        }
        return address;
    }
}

void* operator new[](size_t block, const char *filename, const char *func, int line) {
    return operator new(block, filename, func, line);
}

void deletep(const char *filename="", const char *func="", int line=-1) {
    pfile = filename;
    pline = line;
    pfunc = func;
}

void operator delete(void *address) noexcept {
    try {
        auto tracker = Memcheck::Instance();
        if(selfCall() || tracker == nullptr || pline == -1) {
            free(address);
            return;
        }
        
        selfCall() = true;
        free(address);
        tracker->UnTrack(address);
        selfCall() = false;
        pfile = "";
        pfunc = "";
        pline = -1;
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

void Memcheck::Track(void *address, size_t block, const char* file, const char *func, int line) {
    std::string str(file);
    std::size_t found = str.find_last_of("/\\");
    cout << "Alloc'd " << str.substr(found+1) << ":" << line << " size: " << block << " blocks" << endl;
    
    MemChunk chunk {
        .address = address,
        .size = block,
        .filename = str.substr(found+1),
        .function = func,
        .line = line
    };
    
    chunks.push_back(std::move(chunk));
}

void Memcheck::UnTrack(void *address) {
    auto chunk = std::find_if(std::begin(chunks), std::end(chunks), [=](MemChunk& e) -> bool {
        if (e.address == address) {
            cout << "Dalloc'd " << e.filename << ":" << e.line << " size: "
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
    std::lock_guard<std::mutex> lock(access);
    if(chunks.size() > 0) {
        cout << "======================" << endl;
        cout << "Memory leaks! Missing deallocations for --" << endl;
        int total = 0;
        for(auto&   e : memcheck->chunks) {
            cout << "Alloc'd " << e.filename << ":" << e.line
                 << " " << e.function << "()" << " size: " << e.size << " blocks" << endl;
            total += e.size;
        }
        // Why can't i call clear. Figure out.
        // chunks.clear();
        cout << "Total leak: " << total << " blocks" << endl;
        cout << "======================" << endl;
    }
    cout << "Destroying Memcheck" << endl;
    memcheck = nullptr;
}

Memcheck::Memcheck() {
    cout << "Initializing Memcheck" << endl;
}
