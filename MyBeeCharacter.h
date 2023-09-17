// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyBeeCharacter.generated.h"


//input
//#include "InputAction.h"
//#include "InputActionValue.h"

struct FInputAction;
struct FInputActionValue;


UCLASS()
class BEEHIVE_API AMyBeeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyBeeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* ThirdPersonCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region /** Input */
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UMyInputConfigData* InputActions;

	// 	UPROPERTY(EditDefaultsOnly)
	// 	class UCharacterMovementComponent* CharacterMovement;

		//Handle move input
	void Move(const FInputActionValue& Value);

	//Handle Look input 
	void Look(const FInputActionValue& Value);

	//Stop moving when move input released
	void stopMove(const FInputActionValue& Value);

	void interact(const FInputActionValue& Value);


	//Handle Jump input 
	//void Jump(const FInputActionValue& Value);

	UPROPERTY(EditDefaultsOnly)
		float MoveSpeed = 100;

	UPROPERTY()
		bool ShouldMove = false;

	UPROPERTY()
		FVector MoveDirection;

};
