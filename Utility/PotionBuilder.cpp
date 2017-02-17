#include "PotionBuilder.h"
#include "Item.h"
#include "lpputils.h"

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
					/*
					 * Checks if player has more health than the HP value set by the user, if the item is ready, if the player isn't dead, if a potion isnt already running, if we are not in the fountain,
					 * and if we are not teleporting.
					 */
					return player->HealthPercent() <= menu->GetOption("HP Percent")->GetFloat() && item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning()
					&& !LPPUtils::InFountain(player) && !LPPUtils::IsTeleporting(player, sdk);
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

		items.push_back(
		Item(sdk, "Hunter's potion")
			.setItemInfo(2032, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if player has more health than the HP value set by the user, if the item is ready, if the player isn't dead, if a potion isnt already running, if we are not in the fountain,
					 * and if we are not teleporting.
					 */
					return player->HealthPercent() <= menu->GetOption("HP Percent")->GetFloat() && item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning()
					&& !LPPUtils::InFountain(player) && !LPPUtils::IsTeleporting(player, sdk);
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

	
		items.push_back(
		Item(sdk, "Corrupting Potion")
			.setItemInfo(2033, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if player has more health than the HP value set by the user, if the item is ready, if the player isn't dead, if a potion isnt already running, if we are not in the fountain,
					 * and if we are not teleporting.
					 */
					return player->HealthPercent() <= menu->GetOption("HP Percent")->GetFloat() && item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning()
					&& !LPPUtils::InFountain(player) && !LPPUtils::IsTeleporting(player, sdk);
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

		items.push_back(
		Item(sdk, "Refillable Potion")
			.setItemInfo(2031, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if player has more health than the HP value set by the user, if the item is ready, if the player isn't dead, if a potion isnt already running, if we are not in the fountain,
					 * and if we are not teleporting.
					 */
					return player->HealthPercent() <= menu->GetOption("HP Percent")->GetFloat() && item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning()
					&& !LPPUtils::InFountain(player) && !LPPUtils::IsTeleporting(player, sdk);
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

		items.push_back(
		Item(sdk, "Total Biscuit of Rejuvenation")
			.setItemInfo(2010, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if player has more health than the HP value set by the user, if the item is ready, if the player isn't dead, if a potion isnt already running, if we are not in the fountain,
					 * and if we are not teleporting.
					 */
					return player->HealthPercent() <= menu->GetOption("HP Percent")->GetFloat() && item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning()
					&& !LPPUtils::InFountain(player) && !LPPUtils::IsTeleporting(player, sdk);
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

		items.push_back(
		Item(sdk, "Elixir of Iron")
			.setItemInfo(2138, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if the item is ready, if the player is alive, if we dont already have an active potion, and if we are teleporting
					 */
					return item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning() && !LPPUtils::IsTeleporting(player, sdk);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					item->CastOnPlayer();
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
				})
	);

	
		items.push_back(
		Item(sdk, "Elixir of Sorcery")
			.setItemInfo(2139, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if the item is ready, if the player is alive, if we dont already have an active potion, and if we are teleporting
					 */
					return item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning() && !LPPUtils::IsTeleporting(player, sdk);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					item->CastOnPlayer();
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
				})
	);

		items.push_back(
		Item(sdk, "Elixir of Wrath")
			.setItemInfo(2140, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if the item is ready, if the player is alive, if we dont already have an active potion, and if we are teleporting
					 */
					return item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning() && !LPPUtils::IsTeleporting(player, sdk);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					item->CastOnPlayer();
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
				})
	);

		items.push_back(
		Item(sdk, "Oracle's Extract")
			.setItemInfo(2047, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					/*
					 * Checks if the item is ready, if the player is alive, if we dont already have an active potion, and if we are teleporting
					 */
					return item->IsReady() && !player->IsDead() && !LPPUtils::IsPotRunning() && !LPPUtils::IsTeleporting(player, sdk);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					item->CastOnPlayer();
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
				})
	);

	return items;
}
