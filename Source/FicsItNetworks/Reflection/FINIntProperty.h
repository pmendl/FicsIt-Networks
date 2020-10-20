﻿#pragma once

#include "FINProperty.h"
#include "FINIntProperty.generated.h"

UCLASS(BlueprintType)
class UFINIntProperty : public UFINProperty {
	GENERATED_BODY()
public:
	UPROPERTY()
	UIntProperty* Property = nullptr;
	UPROPERTY()
	UInt64Property* Property64 = nullptr;

	// Begin UFINProperty
	virtual FINAny GetValue(void* Ctx) const override {
		if (Property) return (FINInt)Property->GetPropertyValue_InContainer(Ctx);
		else if (Property64) return Property64->GetPropertyValue_InContainer(Ctx);
		return Super::GetValue(Ctx);
	}
	
	virtual void SetValue(void* Ctx, const FINAny& Value) const override {
		if (Property) Property->SetPropertyValue_InContainer(Ctx, Value.GetInt());
		else if (Property64) Property64->SetPropertyValue_InContainer(Ctx, Value.GetInt());
		return Super::SetValue(Ctx, Value);
	}

	virtual TEnumAsByte<EFINNetworkValueType> GetType() const { return FIN_INT; }
	// End UFINProperty
	
};
