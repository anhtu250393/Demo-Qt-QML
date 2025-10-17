#include <iostream>
#include "pipeclient.h"
#include "messageutils.h"

constexpr int BUFSIZE = 4096;

pipeClient::pipeClient(LPCWSTR pipeName)
{
    m_hPipe = CreateFile( pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (m_hPipe == INVALID_HANDLE_VALUE)
        std::cerr << "Error connecting named pipe: " << GetLastError() << std::endl;
}

bool pipeClient::pingServer(std::string& messageReceive)
{
    std::string messageSend = "Hello from clien!";
    if(messageUtils::sendMessage(m_hPipe, messageSend) == false)
        return false;

    DWORD dwMode = PIPE_READMODE_MESSAGE;
    if (!SetNamedPipeHandleState(m_hPipe, &dwMode, NULL, NULL)) {
        std::cerr << "Error set named pipe to read mode: " << GetLastError() << std::endl;
        return false;
    }

    if(messageUtils::recevieMessage(m_hPipe, messageReceive) == false)
        return false;

    CloseHandle(m_hPipe);

    return true;
}

