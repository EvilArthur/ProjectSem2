#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>


namespace logger {

    enum class Level {
        DEBUG,
        RELEASE,
    };

    enum class Type {
        ERROR,
        DEBUG,
        INFO
    };

    class Logger {
    private:
        static std::ofstream outStream;
        static Level level;


        Logger() = default;

        ~Logger() { outStream.close(); };

        static std::string generateMessage(const std::string& logMessage, const std::string& type) {
            std::time_t timeNow = std::time(nullptr);
            std::string result = type + ": " + logMessage + " | " + std::asctime(std::localtime(&timeNow));
            return result;
        }


    public:

        static void includeFile(const std::string& path = "log.txt") { outStream.open(path); }

        static void d(const std::string& logMessage) {
            std::system("Color 0A");
            if (level != Level::RELEASE)
                std::cout << generateMessage(logMessage, "DEBUG");
            outStream << generateMessage(logMessage, "DEBUG");

        }

        static void info(const std::string& logMessage) {
            std::system("Color 06");
            if (level != Level::RELEASE)
                std::cout << generateMessage(logMessage, "INFO");
            outStream << generateMessage(logMessage, "INFO");
        }

        static void error(const std::string& logMessage) {
            std::system("Color 04");
            if (level != Level::RELEASE)
                std::cout << generateMessage(logMessage, "ERROR");
            outStream << generateMessage(logMessage, "ERROR");
        }
    };
} // logger