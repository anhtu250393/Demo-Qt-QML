#include <iostream>
#include "messageutils.h"

constexpr int BUFSIZE = 4096;

bool messageUtils::sendMessage(HANDLE hPipe, const std::string& message)
{
    DWORD cbWritten;
    BOOL fSuccess = WriteFile(hPipe, message.c_str(), message.size() + 1, &cbWritten, NULL);
    if (!fSuccess || (message.size() + 1) != cbWritten)
    {
        std::cerr << "Error write send message: " << GetLastError() << std::endl;
        return false;
    }

    return true;
}

bool messageUtils::recevieMessage(HANDLE hPip, std::string& message)
{
    BYTE bufferRead[BUFSIZE];
    DWORD bytesRead;
    BOOL fSuccess = ReadFile(hPip, bufferRead, sizeof(bufferRead), &bytesRead, NULL);
    if (!fSuccess || bytesRead == 0)
    {
        std::cerr << "Error read send message: " << GetLastError() << std::endl;
        return false;
    }

    message = std::string(reinterpret_cast<char*>(bufferRead), bytesRead);
    std::cout << "message: " << bufferRead << std::endl;

    return true;
}
