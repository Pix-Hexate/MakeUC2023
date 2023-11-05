// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS  
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "WSock32.lib")


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UDPComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAKEUC2023_API UUDPComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUDPComponent();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Fire();


	const char* serverIP = "192.168.1.184";
	const int serverPort = 33333;
	SOCKET udpSocket;
	const char* message = "switch";
	sockaddr_in serverAddress;
	int messageLength = strlen(message);



protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
