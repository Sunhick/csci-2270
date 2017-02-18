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
#include <mutex>
#include <vector>

using namespace std;

static const char *pfile = "";
static int pline = -1;
static const char* pfunc = "";

// override new operator to track the memory
void* operator new(size_t block, const char *filename, const char *func, int line);
void* operator new[](size_t block, const char *filename, const char *func, int line);

// override delete operator to track the memory
void operator delete(void *address) noexcept;
void operator delete[](void *address) noexcept;

void deletep(const char *filename, const char* func, int line);

#define new     new(__FILE__, __FUNCTION__, __LINE__)
#define delete  deletep(__FILE__, __FUNCTION__, __LINE__), delete

class Memcheck {
public:
    // memory allocation unit
    struct MemChunk {
        void *address;
        size_t size;
        std::string filename;
        std::string function;
        int line;
    };
    
    void Debug(void *address, const char* file, int line);
    static shared_ptr<Memcheck> Instance();
    void Track(void *address, size_t block, const char* file, const char *func, int line);
    void UnTrack(void *address);
    
    ~Memcheck();

private:
    static shared_ptr<Memcheck> memcheck;
    std::mutex access;
    vector<MemChunk> chunks;
    Memcheck();
};

#endif /* memcheck_h */
