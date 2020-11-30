// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FGNET_FGNetGameModeBase_generated_h
#error "FGNetGameModeBase.generated.h already included, missing '#pragma once' in FGNetGameModeBase.h"
#endif
#define FGNET_FGNetGameModeBase_generated_h

#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_SPARSE_DATA
#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_RPC_WRAPPERS
#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFGNetGameModeBase(); \
	friend struct Z_Construct_UClass_AFGNetGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AFGNetGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/FGNet"), NO_API) \
	DECLARE_SERIALIZER(AFGNetGameModeBase)


#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFGNetGameModeBase(); \
	friend struct Z_Construct_UClass_AFGNetGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AFGNetGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/FGNet"), NO_API) \
	DECLARE_SERIALIZER(AFGNetGameModeBase)


#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFGNetGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFGNetGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFGNetGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFGNetGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFGNetGameModeBase(AFGNetGameModeBase&&); \
	NO_API AFGNetGameModeBase(const AFGNetGameModeBase&); \
public:


#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFGNetGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFGNetGameModeBase(AFGNetGameModeBase&&); \
	NO_API AFGNetGameModeBase(const AFGNetGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFGNetGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFGNetGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFGNetGameModeBase)


#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define FGNet_Source_FGNet_FGNetGameModeBase_h_12_PROLOG
#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_SPARSE_DATA \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_RPC_WRAPPERS \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_INCLASS \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FGNet_Source_FGNet_FGNetGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_SPARSE_DATA \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	FGNet_Source_FGNet_FGNetGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FGNET_API UClass* StaticClass<class AFGNetGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FGNet_Source_FGNet_FGNetGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
