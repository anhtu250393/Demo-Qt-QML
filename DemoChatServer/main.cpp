#include <thread>
#include <iostream>

#include "source/pipeserver.h"
#include "source/pipeclient.h"

constexpr LPCWSTR pipeName = L"\\\\.\\pipe\\MyNamedPipe";

int main()
{
    pipeServer server(pipeName);
    HANDLE hEvent = CreateEvent( NULL, TRUE, FALSE, NULL);
    if (hEvent == NULL)
        return 1;

    auto threadWaitMessage = [&]() {
        if(server.create())
            server.waitPipeEvent(hEvent);
    };

    auto threadHandleEvent = [&]() {
        while(true)
        {
            std::cerr << "watting event" << std::endl;
            DWORD waitResult = WaitForSingleObject(hEvent, INFINITE);
            if (waitResult == WAIT_OBJECT_0) {
                std::wcout << "pipeApp: " << server.m_pipeApp << std::endl;
                pipeClient client(server.m_pipeApp.c_str());
                std::string messageSend = "Hello from service!";
                client.pingServer(messageSend);
                return;
            }
        }
    };

    std::thread serveice(threadWaitMessage);
    std::thread event(threadHandleEvent);

    serveice.join();
    event.join();

    system("pause");

    return 0;
}
