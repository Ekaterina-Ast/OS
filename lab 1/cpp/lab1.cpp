#include <iostream>
#include <sysinfoapi.h>
#include <windows.h>
#include <conio.h>

using namespace std;

extern "C" __declspec(dllimport)
BOOL __stdcall GetPhysicallyInstalledSystemMemory(PULONGLONG);

int main()
{
    ULONGLONG TotalMemoryInKilobytes;
    GetPhysicallyInstalledSystemMemory(&TotalMemoryInKilobytes);
    cout <<"RAM="<< TotalMemoryInKilobytes<< " kB" << endl;
    return 0;
}

