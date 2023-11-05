#include <iostream>
#include <winsock2.h>

int main() {
    const char* serverIP = "192.168.1.184"; 
    const int serverPort = 33333; 

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return 1;
    }

    SOCKET udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udpSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create UDP socket" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);

    const char* message = "Switch";
    int messageLength = strlen(message);

    int bytesSent = sendto(udpSocket, message, messageLength, 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Failed to send data" << std::endl;
    } else {
        std::cout << "Sent " << bytesSent << " bytes to the server" << std::endl;
    }

    closesocket(udpSocket);
    WSACleanup();

    return 0;
}
