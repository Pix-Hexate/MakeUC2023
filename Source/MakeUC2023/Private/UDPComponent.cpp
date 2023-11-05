// Fill out your copyright notice in the Description page of Project Settings.


#include "UDPComponent.h"

// Sets default values for this component's properties
UUDPComponent::UUDPComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUDPComponent::BeginPlay()
{
	Super::BeginPlay();
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(serverPort);
	serverAddress.sin_addr.s_addr = inet_addr(serverIP);
}

void UUDPComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	closesocket(udpSocket);
	WSACleanup();
}

// Called every frame
void UUDPComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUDPComponent::Fire() {
	int bytesSent = sendto(udpSocket, message, messageLength, 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

}