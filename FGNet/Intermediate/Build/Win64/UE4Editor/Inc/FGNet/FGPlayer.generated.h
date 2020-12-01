// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef FGNET_FGPlayer_generated_h
#error "FGPlayer.generated.h already included, missing '#pragma once' in FGPlayer.h"
#endif
#define FGNET_FGPlayer_generated_h

#define FGNet_Source_FGNet_Player_FGPlayer_h_15_SPARSE_DATA
#define FGNet_Source_FGNet_Player_FGPlayer_h_15_RPC_WRAPPERS \
	virtual void Multicast_SendLocation_Implementation(FVector const& LocationToSend); \
	virtual void Server_SendLocation_Implementation(FVector const& LocationToSend); \
 \
	DECLARE_FUNCTION(execMulticast_SendLocation); \
	DECLARE_FUNCTION(execServer_SendLocation); \
	DECLARE_FUNCTION(execGetPing); \
	DECLARE_FUNCTION(execIsBraking);


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Multicast_SendLocation_Implementation(FVector const& LocationToSend); \
	virtual void Server_SendLocation_Implementation(FVector const& LocationToSend); \
 \
	DECLARE_FUNCTION(execMulticast_SendLocation); \
	DECLARE_FUNCTION(execServer_SendLocation); \
	DECLARE_FUNCTION(execGetPing); \
	DECLARE_FUNCTION(execIsBraking);


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_EVENT_PARMS \
	struct FGPlayer_eventMulticast_SendLocation_Parms \
	{ \
		FVector LocationToSend; \
	}; \
	struct FGPlayer_eventServer_SendLocation_Parms \
	{ \
		FVector LocationToSend; \
	};


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_CALLBACK_WRAPPERS
#define FGNet_Source_FGNet_Player_FGPlayer_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFGPlayer(); \
	friend struct Z_Construct_UClass_AFGPlayer_Statics; \
public: \
	DECLARE_CLASS(AFGPlayer, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FGNet"), NO_API) \
	DECLARE_SERIALIZER(AFGPlayer)


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFGPlayer(); \
	friend struct Z_Construct_UClass_AFGPlayer_Statics; \
public: \
	DECLARE_CLASS(AFGPlayer, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FGNet"), NO_API) \
	DECLARE_SERIALIZER(AFGPlayer)


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFGPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFGPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFGPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFGPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFGPlayer(AFGPlayer&&); \
	NO_API AFGPlayer(const AFGPlayer&); \
public:


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFGPlayer(AFGPlayer&&); \
	NO_API AFGPlayer(const AFGPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFGPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFGPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFGPlayer)


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComponent() { return STRUCT_OFFSET(AFGPlayer, CollisionComponent); } \
	FORCEINLINE static uint32 __PPO__MeshComponent() { return STRUCT_OFFSET(AFGPlayer, MeshComponent); } \
	FORCEINLINE static uint32 __PPO__SpringArmComponent() { return STRUCT_OFFSET(AFGPlayer, SpringArmComponent); } \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(AFGPlayer, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__MovementComponent() { return STRUCT_OFFSET(AFGPlayer, MovementComponent); }


#define FGNet_Source_FGNet_Player_FGPlayer_h_12_PROLOG \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_EVENT_PARMS


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_SPARSE_DATA \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_RPC_WRAPPERS \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_CALLBACK_WRAPPERS \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_INCLASS \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FGNet_Source_FGNet_Player_FGPlayer_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_SPARSE_DATA \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_CALLBACK_WRAPPERS \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_INCLASS_NO_PURE_DECLS \
	FGNet_Source_FGNet_Player_FGPlayer_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FGNET_API UClass* StaticClass<class AFGPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FGNet_Source_FGNet_Player_FGPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
