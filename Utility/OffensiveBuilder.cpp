#include "Item.h"
#include "OffensiveBuilder.h"

std::vector<ICastable> const &OffensiveBuilder::build(IPluginSDK *sdk, IMenu *parentMenu)
{
	auto potionsMenu = parentMenu->AddMenu("Offensive Items");

	static auto player = sdk->GetEntityList()->Player();

	std::vector<ICastable> items;

	//add items

	return items;
}
