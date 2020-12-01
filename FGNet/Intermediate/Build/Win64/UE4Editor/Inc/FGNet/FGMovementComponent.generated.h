// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FGNET_FGMovementComponent_generated_h
#error "FGMovementComponent.generated.h already included, missing '#pragma once' in FGMovementComponent.h"
#endif
#define FGNET_FGMovementComponent_generated_h

#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_SPARSE_DATA
#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_RPC_WRAPPERS
#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFGMovementComponent(); \
	friend struct Z_Construct_UClass_UFGMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UFGMovementComponent, UMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FGNet"), NO_API) \
	DECLARE_SERIALIZER(UFGMovementComponent)


#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUFGMovementComponent(); \
	friend struct Z_Construct_UClass_UFGMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UFGMovementComponent, UMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FGNet"), NO_API) \
	DECLARE_SERIALIZER(UFGMovementComponent)


#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFGMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFGMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFGMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFGMovementComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFGMovementComponent(UFGMovementComponent&&); \
	NO_API UFGMovementComponent(const UFGMovementComponent&); \
public:


#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFGMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFGMovementComponent(UFGMovementComponent&&); \
	NO_API UFGMovementComponent(const UFGMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFGMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFGMovementComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFGMovementComponent)


#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_PRIVATE_PROPERTY_OFFSET
#define FGNet_Source_FGNet_Components_FGMovementComponent_h_8_PROLOG
#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_PRIVATE_PROPERTY_OFFSET \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_SPARSE_DATA \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_RPC_WRAPPERS \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_INCLASS \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FGNet_Source_FGNet_Components_FGMovementComponent_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_PRIVATE_PROPERTY_OFFSET \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_SPARSE_DATA \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_INCLASS_NO_PURE_DECLS \
	FGNet_Source_FGNet_Components_FGMovementComponent_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FGNET_API UClass* StaticClass<class UFGMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FGNet_Source_FGNet_Components_FGMovementComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
