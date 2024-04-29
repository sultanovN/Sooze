// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Sooze/SoozeCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoozeCharacter() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	SOOZE_API UClass* Z_Construct_UClass_ASoozeCharacter();
	SOOZE_API UClass* Z_Construct_UClass_ASoozeCharacter_NoRegister();
	SOOZE_API UClass* Z_Construct_UClass_UCustomCharacterMovementComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Sooze();
// End Cross Module References
	DEFINE_FUNCTION(ASoozeCharacter::execGetCustomCharacterMovement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCustomCharacterMovementComponent**)Z_Param__Result=P_THIS->GetCustomCharacterMovement();
		P_NATIVE_END;
	}
	void ASoozeCharacter::StaticRegisterNativesASoozeCharacter()
	{
		UClass* Class = ASoozeCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCustomCharacterMovement", &ASoozeCharacter::execGetCustomCharacterMovement },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics
	{
		struct SoozeCharacter_eventGetCustomCharacterMovement_Parms
		{
			UCustomCharacterMovementComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SoozeCharacter_eventGetCustomCharacterMovement_Parms, ReturnValue), Z_Construct_UClass_UCustomCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoozeCharacter, nullptr, "GetCustomCharacterMovement", nullptr, nullptr, Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::SoozeCharacter_eventGetCustomCharacterMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::SoozeCharacter_eventGetCustomCharacterMovement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASoozeCharacter);
	UClass* Z_Construct_UClass_ASoozeCharacter_NoRegister()
	{
		return ASoozeCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASoozeCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GliderMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GliderMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GlideAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DiveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DiveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClimbAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ClimbAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CancelClimbAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CancelClimbAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DescendingRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DescendingRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinimumHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideRotationRate_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GlideRotationRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideAirControl_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideAirControl;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideBrakingDecelerationFalling_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideBrakingDecelerationFalling;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideAcceleration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideAcceleration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideWalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideWalkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideMaxAcceleration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideMaxAcceleration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideMaxWalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideMaxWalkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DiveDecendingRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveDecendingRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DiveSpeedIncrease_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveSpeedIncrease;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DiveAccelerationIncrease_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveAccelerationIncrease;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DiveMaxSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveMaxSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlideSpeedDecreaseFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GlideSpeedDecreaseFactor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredCameraFOV_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredCameraFOV;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsGliding_MetaData[];
#endif
		static void NewProp_IsGliding_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsGliding;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoozeCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Sooze,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ASoozeCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASoozeCharacter_GetCustomCharacterMovement, "GetCustomCharacterMovement" }, // 3906636790
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SoozeCharacter.h" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GliderMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GliderMesh = { "GliderMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GliderMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GliderMesh_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GliderMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAction = { "GlideAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAction = { "DiveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DiveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_ClimbAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_ClimbAction = { "ClimbAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, ClimbAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_ClimbAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_ClimbAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CancelClimbAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CancelClimbAction = { "CancelClimbAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, CancelClimbAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CancelClimbAction_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CancelClimbAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DescendingRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DescendingRate = { "DescendingRate", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DescendingRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DescendingRate_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DescendingRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MinimumHeight_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MinimumHeight = { "MinimumHeight", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, MinimumHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MinimumHeight_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MinimumHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideRotationRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideRotationRate = { "GlideRotationRate", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideRotationRate), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideRotationRate_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideRotationRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAirControl_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAirControl = { "GlideAirControl", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideAirControl), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAirControl_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAirControl_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideBrakingDecelerationFalling_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideBrakingDecelerationFalling = { "GlideBrakingDecelerationFalling", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideBrakingDecelerationFalling), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideBrakingDecelerationFalling_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideBrakingDecelerationFalling_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAcceleration_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAcceleration = { "GlideAcceleration", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideAcceleration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAcceleration_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAcceleration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideWalkSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideWalkSpeed = { "GlideWalkSpeed", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideWalkSpeed_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideWalkSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxAcceleration_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxAcceleration = { "GlideMaxAcceleration", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideMaxAcceleration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxAcceleration_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxAcceleration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxWalkSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxWalkSpeed = { "GlideMaxWalkSpeed", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideMaxWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxWalkSpeed_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxWalkSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveDecendingRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveDecendingRate = { "DiveDecendingRate", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DiveDecendingRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveDecendingRate_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveDecendingRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveSpeedIncrease_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveSpeedIncrease = { "DiveSpeedIncrease", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DiveSpeedIncrease), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveSpeedIncrease_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveSpeedIncrease_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAccelerationIncrease_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAccelerationIncrease = { "DiveAccelerationIncrease", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DiveAccelerationIncrease), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAccelerationIncrease_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAccelerationIncrease_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveMaxSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveMaxSpeed = { "DiveMaxSpeed", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DiveMaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveMaxSpeed_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveMaxSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideSpeedDecreaseFactor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideSpeedDecreaseFactor = { "GlideSpeedDecreaseFactor", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, GlideSpeedDecreaseFactor), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideSpeedDecreaseFactor_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideSpeedDecreaseFactor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DesiredCameraFOV_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DesiredCameraFOV = { "DesiredCameraFOV", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, DesiredCameraFOV), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DesiredCameraFOV_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DesiredCameraFOV_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoozeCharacter, MovementComponent), Z_Construct_UClass_UCustomCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MovementComponent_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MovementComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SoozeCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding_SetBit(void* Obj)
	{
		((ASoozeCharacter*)Obj)->IsGliding = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding = { "IsGliding", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASoozeCharacter), &Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding_MetaData), Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASoozeCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GliderMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_ClimbAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_CancelClimbAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DescendingRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MinimumHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideRotationRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAirControl,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideBrakingDecelerationFalling,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideAcceleration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideWalkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxAcceleration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideMaxWalkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveDecendingRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveSpeedIncrease,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveAccelerationIncrease,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DiveMaxSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_GlideSpeedDecreaseFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_DesiredCameraFOV,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_MovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoozeCharacter_Statics::NewProp_IsGliding,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoozeCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoozeCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASoozeCharacter_Statics::ClassParams = {
		&ASoozeCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASoozeCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ASoozeCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASoozeCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASoozeCharacter()
	{
		if (!Z_Registration_Info_UClass_ASoozeCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASoozeCharacter.OuterSingleton, Z_Construct_UClass_ASoozeCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASoozeCharacter.OuterSingleton;
	}
	template<> SOOZE_API UClass* StaticClass<ASoozeCharacter>()
	{
		return ASoozeCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoozeCharacter);
	ASoozeCharacter::~ASoozeCharacter() {}
	struct Z_CompiledInDeferFile_FID_UE_Projects_Sooze_Source_Sooze_SoozeCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Projects_Sooze_Source_Sooze_SoozeCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASoozeCharacter, ASoozeCharacter::StaticClass, TEXT("ASoozeCharacter"), &Z_Registration_Info_UClass_ASoozeCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASoozeCharacter), 1933138504U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Projects_Sooze_Source_Sooze_SoozeCharacter_h_1563402225(TEXT("/Script/Sooze"),
		Z_CompiledInDeferFile_FID_UE_Projects_Sooze_Source_Sooze_SoozeCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Projects_Sooze_Source_Sooze_SoozeCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
