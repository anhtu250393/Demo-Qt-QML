#ifndef NAMEDPIPEHANDLER_H
#define NAMEDPIPEHANDLER_H

#include <windows.h>

class namedPipeHandler
{
public:
    namedPipeHandler(LPCSTR m_pipeName);
    ~namedPipeHandler();

    bool create();
    void waitPipeEvent();

private:
    const LPCSTR m_pipeName;
    HANDLE m_hPipe = nullptr;
};

#endif // NAMEDPIPEHANDLER_H
