#include <iostream>

#include "namedpipehandler.h"
#include "messageutils.h"

constexpr int BUFSIZE = 4096;

namedPipeHandler::namedPipeHandler(LPCSTR pipeName): m_pipeName(pipeName) {}

namedPipeHandler::~namedPipeHandler()
{
    CloseHandle(m_hPipe);
}

bool namedPipeHandler::create()
{
    m_hPipe = CreateNamedPipe (
        TEXT(m_pipeName), // Pipe name
        PIPE_ACCESS_DUPLEX,              // Read/write access
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, // Message-type, message-read, blocking mode
        PIPE_UNLIMITED_INSTANCES,        // Max instances
        BUFSIZE,                         // Output buffer size
        BUFSIZE,                         // Input buffer size
        0,                               // Default timeout
        NULL                             // Default security attributes
        );

    if (m_hPipe == INVALID_HANDLE_VALUE) {
        std::cerr << "Error creating named pipe: " << GetLastError() << std::endl;
        return false;
    }

    return true;
}

void namedPipeHandler::waitPipeEvent()
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

            std::cout << "read: " << messageReceive << std::endl;

            std::string messageSend = "Hello from service!";
            if(messageUtils::sendMessage(m_hPipe, messageSend) == false)
                return;

            DisconnectNamedPipe(m_hPipe);

        } else {
            std::cerr << "Error connecting named pipe: " << GetLastError() << std::endl;
        }
    }
}
