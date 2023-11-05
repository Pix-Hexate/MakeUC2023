#include <iostream>
#include <windows.h>


using namespace std;
int main(void) {
    system("pnputil /disable-device \"USB\\VID_1A86&PID_7523\\6&1d6d3eb5&0&2\"");
    std::cout << "Disabled USB ports";
    Sleep(1000);
    system("pnputil /enable-device \"USB\\VID_1A86&PID_7523\\6&1d6d3eb5&0&2\"");
}