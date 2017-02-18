//
//  memcheck.h
//  Memcheck
//
//  Created by Sunil on 2/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef memcheck_h
#define memcheck_h

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

static const char *file;
static int pline;

// override new operator to track the memory
void* operator new(size_t block, const char *filename, int line);
void* operator new[](size_t block, const char *filename, int line);

// override delete operator to track the memory
void operator delete(void *address) noexcept;
void operator delete[](void *address) noexcept;

void deletep(const char *filename, int line);

#define new     new(__FILE__, __LINE__)
// #define delete  deletep(__FILE__, __LINE__), delete

class Memcheck {
public:
    // memory allocation unit
    struct MemChunk {
        void *address;
        size_t size;
        std::string file;
        int line;
    };
    
    void Debug(void *address, const char* file, int line);
    static shared_ptr<Memcheck> Instance();
    void Track(void *address, size_t block, const char* file, int line);
    void UnTrack(void *address);
    
    ~Memcheck();

private:
    static shared_ptr<Memcheck> memcheck;
    vector<MemChunk> chunks;
    Memcheck();
};

#endif /* memcheck_h */
