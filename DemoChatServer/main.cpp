#include "source/namedpipehandler.h"

constexpr LPCSTR pipeName = "\\\\.\\pipe\\MyNamedPipe";

int main()
{
    namedPipeHandler pipeHandler(pipeName);
    if(pipeHandler.create())
        pipeHandler.waitPipeEvent();

    system("pause");

    return 0;
}
