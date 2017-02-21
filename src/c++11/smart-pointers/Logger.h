//
//  Logger.hpp
//  SmartPointers
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Logger_h
#define Logger_h

#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>
#include <mutex>

namespace Logging {
    // logger interface
    class Logger {
    private:
        std::string id;
        using StreamType = std::ofstream;
        std::unique_ptr<StreamType, std::function<void(StreamType*)>> file;
        std::mutex access;
        
    public:
        Logger(std::string filename);
        Logger(Logger& logger);
        ~Logger();
        Logger& operator << (const std::string message) noexcept(true);
        void Log(const std::string message) noexcept(true);
    };
}

#endif /* Logger_h */
