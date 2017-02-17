#include "Item.h"
#include "DefensiveBuilder.h"

std::vector<ICastable> const &DefensiveBuilder::build(IPluginSDK *sdk, IMenu *parentMenu)
{
	auto potionsMenu = parentMenu->AddMenu("Defensive Items");

	static auto player = sdk->GetEntityList()->Player();

	std::vector<ICastable> items;

	//add items

	return items;
}
