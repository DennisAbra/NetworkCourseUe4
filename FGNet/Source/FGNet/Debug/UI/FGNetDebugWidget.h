#pragma once
#include "Blueprint/UserWidget.h"
#include "FGNetDebugWidget.generated.h"

USTRUCT(BlueprintType)
struct FFGBlueprintNetworkSimulationSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Settings", meta = (DisplayName = "Min Latency", ClampMin = "0", ClampMax = "5000"))
		int32 MinLatency = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Settings", meta = (DisplayName = "Max Latency", ClampMin = "0", ClampMax = "5000"))
		int32 MaxLatency = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Settings", meta = (ClampMin = "0", ClampMax = "5000"))
		int32 PacketLossPercentage = 0;
};

USTRUCT(BlueprintType)
struct FFGBlueprintNetworkSimulationSettingsText
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Network Settings", meta = (DisplayName = "Min Latency"))
		FText MinLatency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Network Settings", meta = (DisplayName = "Max Latency"))
		FText MaxLatency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Settings")
		FText PacketLossPercentage;
};

UCLASS()
class FGNET_API UFGNetDebugWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = Widget)
	void UpdateNetworkSimulationSettings(const FFGBlueprintNetworkSimulationSettings& InPackets);

	UFUNCTION(BlueprintImplementableEvent, Category = Widget, meta = (DisplayName = "On Update Network Simulation Settings"))
	void BP_OnUpdateNetworkSimulationSettings(const FFGBlueprintNetworkSimulationSettingsText& Packets);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = Widget, meta = (DisplayName = "On Update Ping"))
	void BP_UpdatePing(int32 ping);

	UFUNCTION(BlueprintImplementableEvent, Category = Widget, meta = (DisplayName = "On Show Widget"))
	void BP_OnShowWidget();

	UFUNCTION(BlueprintImplementableEvent, Category = Widget, meta = (DisplayName = "On Hide Ping"))
	void BP_OnHideWidget();
};
