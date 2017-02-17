#include "PotionBuilder.h"
#include "Item.h"

std::vector<ICastable> const &PotionBuilder::build(IPluginSDK *sdk, IMenu *parentMenu)
{
	auto potionsMenu = parentMenu->AddMenu("Offensive Items");

	static auto player = sdk->GetEntityList()->Player();

	std::vector<ICastable> items;

	//add items

	return items;
}
