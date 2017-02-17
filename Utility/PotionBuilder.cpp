#include "PotionBuilder.h"
#include "Item.h"

std::vector<ICastable> const &PotionBuilder::build(IPluginSDK *sdk, IMenu *parentMenu)
{
	auto potionsMenu = parentMenu->AddMenu("Potions");

	static auto player = sdk->GetEntityList()->Player();

	std::vector<ICastable> items;

	items.push_back(
		Item(sdk, "Health Potion")
			.setItemInfo(2003, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					//conditions for being able to use the item (return true or false)
					return player->HealthPercent() <= menu->GetOption("HP Percent")->GetFloat();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					item->CastOnPlayer();
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("HP Percent", 0.f, 100.f, 35.f);
				})
	);

	return items;
}
