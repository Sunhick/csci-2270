//
//  Logger.cpp
//  SmartPointers
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//
#include <chrono>
#include <iomanip>
#include <ctime>
#include <thread>

#include "Logger.h"

using namespace Logging;

Logger::Logger(std::string filename) {
    auto deleter = [](std::ofstream* file) -> void {
        std::cout << "Deleting file object" << std::endl;
        delete file;
    };
    
    // std::cout << typeid(decltype(deleter)).name() << std::endl;
    
    std::time_t result = std::time(nullptr);
    id = std::asctime(std::localtime(&result));
    file = std::unique_ptr<StreamType, std::function<void(StreamType*)>>(new StreamType, deleter);
    file->open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
}

Logger::Logger(Logger& logger) {
#if DEBUG
    // only for debugging purpose. To generate unique Id
    // separated by atleast 3 seconds.
    std::this_thread::sleep_for(std::chrono::seconds(3));
#endif
    
    std::time_t result = std::time(nullptr);
    id = std::asctime(std::localtime(&result));
    this->file = std::move(logger.file);
    logger.file = nullptr;
}

Logger::~Logger() {
    if (file) {
        file->close();
    }
}

Logger& Logger::operator<<(const std::string message) noexcept(true) {
    try {
        std::lock_guard<std::mutex> lock(access);
        
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        
        *file << "DEBUG: " << std::put_time(std::localtime(&now_c), "%c") << " " << message << std::endl;
    }
    catch(...) {
        // no exceptions
    }
    
    return *this;
}

void Logger::Log(const std::string message) noexcept(true) {
    operator<<(message);
}
