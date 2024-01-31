#include "logger/Logs.h"

Logs::Logs()
{

}

Logs::~Logs()
{

}

void Logs::log(const std::string& message)
{
    std::cout << message << "\n";
    return;
}

void Logs::exitWithError(const std::string& message)
{
    log("ERROR: " + message);
    exit(1);
}