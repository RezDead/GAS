// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ManaAttributeSet.generated.h"

UCLASS()
class GAS_API UManaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	public:

	UManaAttributeSet();

	//Mana Attribute
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS_BASIC(UManaAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS_BASIC(UManaAttributeSet, MaxMana);
	
public:
	//Replications
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UManaAttributeSet, Mana, OldMana);
	}

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UManaAttributeSet, MaxMana, OldMaxMana);
	}

	//Determines how values are replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
