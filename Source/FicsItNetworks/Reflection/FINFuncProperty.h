﻿#pragma once

#include "FINProperty.h"
#include "FINFuncProperty.generated.h"

UCLASS(BlueprintType)
class UFINFuncProperty : public UFINProperty {
	GENERATED_BODY()
public:
	UPROPERTY()
	FFINPropertyGetterFunc GetterFunc;
	UPROPERTY()
	FFINPropertySetterFunc SetterFunc;

	// Begin UFINProperty
	virtual FINAny GetValue(void* Ctx) const override {
		return GetterFunc(Ctx);
	}
	
	virtual void SetValue(void* Ctx, const FINAny& Value) const override {
		SetterFunc(Ctx, Value);
	}
	// End UFINProperty
};
