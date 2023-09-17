// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBeeCharacter.h"

//input
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "MyInputConfigData.h"

//Actor components
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyBeeCharacter::AMyBeeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));//Creating spring arm
	SpringArmComp->SetupAttachment(GetMesh());//Setting up attachment to the mesh


	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void AMyBeeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBeeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBeeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PC = Cast<APlayerController>(GetController());

	// Get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	//Clear out existing mapping, and add our mapping
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	//Getting the EnhancedInputComponent
	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	//Binding the actions
	PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AMyBeeCharacter::Move);
	//PEI->BindAction(InputActions->InputMove, ETriggerEvent::Completed, this, &AMyCharacterCPP::stopMove);
	PEI->BindAction(InputActions->InputLook, ETriggerEvent::Triggered, this, &AMyBeeCharacter::Look);
	PEI->BindAction(InputActions->InputInteract, ETriggerEvent::Triggered, this, &AMyBeeCharacter::interact);



}

void AMyBeeCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
		}
}

void AMyBeeCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookValue = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookValue.X);
		AddControllerPitchInput(LookValue.Y);
	}
}

void AMyBeeCharacter::stopMove(const FInputActionValue& Value)
{

}

void AMyBeeCharacter::interact(const FInputActionValue& Value)
{

}

