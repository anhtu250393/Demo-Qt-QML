#ifndef PIPECLIENT_H
#define PIPECLIENT_H

#include <windows.h>
#include <string>

class pipeClient
{
public:
    pipeClient(LPCWSTR pipeName);

    bool pingServer(const std::string& messageSend);
private:
    HANDLE m_hPipe;
};

#endif // PIPECLIENT_H
