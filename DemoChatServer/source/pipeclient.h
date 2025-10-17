#ifndef PIPECLIENT_H
#define PIPECLIENT_H

#include <windows.h>
class pipeClient
{
public:
    pipeClient(LPCWSTR pipeName);

    bool pingServer(std::string& messageReceive);
private:
    HANDLE m_hPipe;
};

#endif // PIPECLIENT_H
