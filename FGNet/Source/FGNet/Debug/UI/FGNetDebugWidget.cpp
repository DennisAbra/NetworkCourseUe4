#include "FGNetDebugWidget.h"
#include "Engine/World.h"
#include "Engine/NetDriver.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Misc/DefaultValueHelper.h"

void UFGNetDebugWidget::UpdateNetworkSimulationSettings(const FFGBlueprintNetworkSimulationSettings& InPackets)
{
	if (UWorld* World = GetWorld())
	{
		if (World->GetNetDriver() != nullptr)
		{
			FPacketSimulationSettings PacketSimulation;
			PacketSimulation.PktLagMin = InPackets.MinLatency;
			PacketSimulation.PktLagMax = InPackets.MaxLatency;
			PacketSimulation.PktLoss = InPackets.PacketLossPercentage;
			PacketSimulation.PktIncomingLagMin = InPackets.MinLatency;
			PacketSimulation.PktIncomingLagMax = InPackets.MaxLatency;
			PacketSimulation.PktIncomingLoss = InPackets.PacketLossPercentage;
			World->GetNetDriver()->SetPacketSimulationSettings(PacketSimulation);

			FFGBlueprintNetworkSimulationSettingsText SimlulationSettingsText;
			SimlulationSettingsText.MaxLatency = FText::FromString(FString::FromInt(InPackets.MaxLatency));
			SimlulationSettingsText.MinLatency = FText::FromString(FString::FromInt(InPackets.MinLatency));
			SimlulationSettingsText.PacketLossPercentage = FText::FromString(FString::FromInt(InPackets.PacketLossPercentage));

			BP_OnUpdateNetworkSimulationSettings(SimlulationSettingsText);
		}
	}
}

void UFGNetDebugWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (APlayerController* 
		PC = GetOwningPlayer())
	{
		if (APlayerState* PlayerState = PC->GetPlayerState<APlayerState>())
		{
			BP_UpdatePing(static_cast<int32>(PlayerState->GetPing()));
		}
	}
}


