#ifndef LOGS_H
#define LOGS_H

#include <iostream>
#include <string>

class Logs{
    public:
        Logs();
        ~Logs();
        void log(const std::string& message);
        void exitWithError(const std::string& message);
};

#endif