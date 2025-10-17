#ifndef MESSAGEUTILS_H
#define MESSAGEUTILS_H

#include <windows.h>
#include <string>
class messageUtils
{
public:
    static bool sendMessage(HANDLE hPipe, const std::string& message);
    static bool recevieMessage(HANDLE hPip, std::string& message);
};

#endif // MESSAGEUTILS_H
