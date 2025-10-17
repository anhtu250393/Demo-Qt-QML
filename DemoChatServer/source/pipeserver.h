#ifndef PIPESERVER_H
#define PIPESERVER_H

#include <windows.h>
#include <string>

class pipeServer
{
public:
    pipeServer(LPCWSTR m_pipeName);
    ~pipeServer();

    bool create();
    void waitPipeEvent(HANDLE hEvent);

public:
    std::wstring m_pipeApp;

private:
    const LPCWSTR m_pipeName;
    HANDLE m_hPipe = nullptr;
};

#endif // PIPESERVER_H
