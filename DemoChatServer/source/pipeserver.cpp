#include <iostream>
#include <codecvt>
#include <locale>

#include "pipeserver.h"
#include "messageutils.h"

constexpr int BUFSIZE = 4096;

pipeServer::pipeServer(LPCWSTR pipeName): m_pipeName(pipeName) {}

pipeServer::~pipeServer()
{
    CloseHandle(m_hPipe);
}

bool pipeServer::create()
{
    m_hPipe = CreateNamedPipeW(m_pipeName,  PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, BUFSIZE, BUFSIZE, 0, NULL);

    if (m_hPipe == INVALID_HANDLE_VALUE) {
        std::cerr << "Error creating named pipe: " << GetLastError() << std::endl;
        return false;
    }

    return true;
}

void pipeServer::waitPipeEvent(HANDLE hEvent)
{
    std::cout << "Named pipe created. Waiting for client..." << std::endl;
    if(m_hPipe == nullptr)
        return;

    while(true)
    {
        if (ConnectNamedPipe(m_hPipe, NULL) != FALSE) {
            std::cout << "Client connected!" << std::endl;

            std::string messageReceive = "";
            if(messageUtils::recevieMessage(m_hPipe, messageReceive) == false)
                return;

            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
            m_pipeApp = m_pipeName + converter.from_bytes(messageReceive);

            SetEvent(hEvent);

            // std::string messageSend = "Hello from service!";
            //if(messageUtils::sendMessage(m_hPipe, messageSend) == false)
            //     return;

            DisconnectNamedPipe(m_hPipe);

        } else {
            std::cerr << "Error connecting named pipe: " << GetLastError() << std::endl;
        }
    }
}
