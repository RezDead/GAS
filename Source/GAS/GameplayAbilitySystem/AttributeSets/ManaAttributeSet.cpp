// Fill out your copyright notice in the Description page of Project Settings.


#include "ManaAttributeSet.h"
#include "Net/UnrealNetwork.h"

UManaAttributeSet::UManaAttributeSet()
{
	Mana = 100.f;
	MaxMana = 100.f;
}

void UManaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UManaAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UManaAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

