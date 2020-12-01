// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FGNet/Player/FGPlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFGPlayer() {}
// Cross Module References
	FGNET_API UClass* Z_Construct_UClass_AFGPlayer_NoRegister();
	FGNET_API UClass* Z_Construct_UClass_AFGPlayer();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_FGNet();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	FGNET_API UClass* Z_Construct_UClass_UFGMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFGPlayer::execMulticast_SendLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_LocationToSend);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Multicast_SendLocation_Implementation(Z_Param_LocationToSend);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFGPlayer::execServer_SendLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_LocationToSend);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SendLocation_Implementation(Z_Param_LocationToSend);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFGPlayer::execGetPing)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetPing();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFGPlayer::execIsBraking)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsBraking();
		P_NATIVE_END;
	}
	static FName NAME_AFGPlayer_Multicast_SendLocation = FName(TEXT("Multicast_SendLocation"));
	void AFGPlayer::Multicast_SendLocation(FVector const& LocationToSend)
	{
		FGPlayer_eventMulticast_SendLocation_Parms Parms;
		Parms.LocationToSend=LocationToSend;
		ProcessEvent(FindFunctionChecked(NAME_AFGPlayer_Multicast_SendLocation),&Parms);
	}
	static FName NAME_AFGPlayer_Server_SendLocation = FName(TEXT("Server_SendLocation"));
	void AFGPlayer::Server_SendLocation(FVector const& LocationToSend)
	{
		FGPlayer_eventServer_SendLocation_Parms Parms;
		Parms.LocationToSend=LocationToSend;
		ProcessEvent(FindFunctionChecked(NAME_AFGPlayer_Server_SendLocation),&Parms);
	}
	void AFGPlayer::StaticRegisterNativesAFGPlayer()
	{
		UClass* Class = AFGPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPing", &AFGPlayer::execGetPing },
			{ "IsBraking", &AFGPlayer::execIsBraking },
			{ "Multicast_SendLocation", &AFGPlayer::execMulticast_SendLocation },
			{ "Server_SendLocation", &AFGPlayer::execServer_SendLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFGPlayer_GetPing_Statics
	{
		struct FGPlayer_eventGetPing_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AFGPlayer_GetPing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGPlayer_eventGetPing_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFGPlayer_GetPing_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFGPlayer_GetPing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFGPlayer_GetPing_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFGPlayer_GetPing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFGPlayer, nullptr, "GetPing", nullptr, nullptr, sizeof(FGPlayer_eventGetPing_Parms), Z_Construct_UFunction_AFGPlayer_GetPing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_GetPing_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFGPlayer_GetPing_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_GetPing_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFGPlayer_GetPing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFGPlayer_GetPing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFGPlayer_IsBraking_Statics
	{
		struct FGPlayer_eventIsBraking_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FGPlayer_eventIsBraking_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FGPlayer_eventIsBraking_Parms), &Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFGPlayer, nullptr, "IsBraking", nullptr, nullptr, sizeof(FGPlayer_eventIsBraking_Parms), Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFGPlayer_IsBraking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFGPlayer_IsBraking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocationToSend_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LocationToSend;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::NewProp_LocationToSend_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::NewProp_LocationToSend = { "LocationToSend", nullptr, (EPropertyFlags)0x0010000008000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGPlayer_eventMulticast_SendLocation_Parms, LocationToSend), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::NewProp_LocationToSend_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::NewProp_LocationToSend_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::NewProp_LocationToSend,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFGPlayer, nullptr, "Multicast_SendLocation", nullptr, nullptr, sizeof(FGPlayer_eventMulticast_SendLocation_Parms), Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00824C40, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocationToSend_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LocationToSend;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::NewProp_LocationToSend_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::NewProp_LocationToSend = { "LocationToSend", nullptr, (EPropertyFlags)0x0010000008000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGPlayer_eventServer_SendLocation_Parms, LocationToSend), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::NewProp_LocationToSend_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::NewProp_LocationToSend_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::NewProp_LocationToSend,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFGPlayer, nullptr, "Server_SendLocation", nullptr, nullptr, sizeof(FGPlayer_eventServer_SendLocation_Parms), Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20C40, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFGPlayer_Server_SendLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFGPlayer_Server_SendLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFGPlayer_NoRegister()
	{
		return AFGPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AFGPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArmComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArmComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultFriction_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultFriction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BrakingFriction_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BrakingFriction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TurnSpeedDefault_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TurnSpeedDefault;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Acceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Acceleration;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFGPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_FGNet,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFGPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFGPlayer_GetPing, "GetPing" }, // 3470852645
		{ &Z_Construct_UFunction_AFGPlayer_IsBraking, "IsBraking" }, // 604336299
		{ &Z_Construct_UFunction_AFGPlayer_Multicast_SendLocation, "Multicast_SendLocation" }, // 1265338654
		{ &Z_Construct_UFunction_AFGPlayer_Server_SendLocation, "Server_SendLocation" }, // 3017937005
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/FGPlayer.h" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, MovementComponent), Z_Construct_UClass_UFGMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_MovementComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_CameraComponent_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_CameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_CameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_SpringArmComponent_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_SpringArmComponent = { "SpringArmComponent", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, SpringArmComponent), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_SpringArmComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_SpringArmComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_MeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_MeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_CollisionComponent_MetaData[] = {
		{ "Category", "Collision" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_CollisionComponent = { "CollisionComponent", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, CollisionComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_CollisionComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_CollisionComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_DefaultFriction_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMax", "1.000000" },
		{ "ClampMin", "0.000000" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_DefaultFriction = { "DefaultFriction", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, DefaultFriction), METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_DefaultFriction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_DefaultFriction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_BrakingFriction_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMax", "1.000000" },
		{ "ClampMin", "0.000000" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_BrakingFriction = { "BrakingFriction", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, BrakingFriction), METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_BrakingFriction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_BrakingFriction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_MaxVelocity_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_MaxVelocity = { "MaxVelocity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, MaxVelocity), METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_MaxVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_MaxVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_TurnSpeedDefault_MetaData[] = {
		{ "Category", "Movement" },
		{ "DisplayName", "TurnSpeed" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_TurnSpeedDefault = { "TurnSpeedDefault", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, TurnSpeedDefault), METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_TurnSpeedDefault_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_TurnSpeedDefault_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFGPlayer_Statics::NewProp_Acceleration_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Player/FGPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFGPlayer_Statics::NewProp_Acceleration = { "Acceleration", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFGPlayer, Acceleration), METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::NewProp_Acceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::NewProp_Acceleration_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFGPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_MovementComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_CameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_SpringArmComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_MeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_CollisionComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_DefaultFriction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_BrakingFriction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_MaxVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_TurnSpeedDefault,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFGPlayer_Statics::NewProp_Acceleration,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFGPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFGPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFGPlayer_Statics::ClassParams = {
		&AFGPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFGPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFGPlayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFGPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFGPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFGPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFGPlayer, 2517312863);
	template<> FGNET_API UClass* StaticClass<AFGPlayer>()
	{
		return AFGPlayer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFGPlayer(Z_Construct_UClass_AFGPlayer, &AFGPlayer::StaticClass, TEXT("/Script/FGNet"), TEXT("AFGPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFGPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
