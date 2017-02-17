#include "Item.h"
#include "OffensiveBuilder.h"
#include "lpputils.h"

std::vector<ICastable> const &OffensiveBuilder::build(IPluginSDK *sdk, IMenu *parentMenu)
{
	auto potionsMenu = parentMenu->AddMenu("Offensive Items");

	static auto player = sdk->GetEntityList()->Player();
	static auto orbwalking = sdk->GetOrbwalking();

	std::vector<ICastable> items;

		items.push_back(
		Item(sdk, "Blade of the Ruined King")
			.setItemInfo(3153, 550.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
			// Gets the HP of our player and if its above the value set by the user and item is ready we will use
					return player->HealthPercent() <= menu->GetOption("HP to use")->GetFloat() && item->IsReady();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//gets all enemy heros
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						// if we are chasing the enemy OR the enemy is chasing us, and the enemy is in range and meets the HP requirements, use item
						if (enemy->IsValidTarget() && (player->IsChasing(enemy) || enemy->IsChasing(player)) && item->IsTargetInRange(enemy) && enemy->GetHealth() >= menu->GetOption("Enemy HP")->GetFloat())
						{
							item->CastOnTarget(enemy);
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("Enemy HP to use", 0.f, 100.f, 75.f);
					menu->AddFloat("HP to use", 0.f, 100.f, 75.f);
				})
	);


		items.push_back(
		Item(sdk, "Bilgewater Cutlass")
			.setItemInfo(3144, 550.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return player->HealthPercent() <= menu->GetOption("HP to use")->GetFloat() && item->IsReady();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && (player->IsChasing(enemy) || enemy->IsChasing(player)) && item->IsTargetInRange(enemy) && enemy->GetHealth() >= menu->GetOption("Enemy HP")->GetFloat())
						{
							item->CastOnTarget(enemy);
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("Enemy HP to use", 0.f, 100.f, 75.f);
					menu->AddFloat("HP to use", 0.f, 100.f, 75.f);
				})
	);


		items.push_back(
		Item(sdk, "Frost Queen's Claim")
			.setItemInfo(3092, 1500.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return player->HealthPercent() <= menu->GetOption("Dont use under HP")->GetFloat() && item->IsReady();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && item->IsTargetInRange(enemy) && enemy->HealthPercent() <= menu->GetOption("Enemy HP")->GetFloat());
						{
							item->CastOnTarget(enemy);
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("Dont use under HP", 0.f, 100.f, 40.f);
					menu->AddFloat("Enemy HP", 0.f, 100.f, 65.f);
				})
	);

		items.push_back(
		Item(sdk, "Hextech Gunblade")
			.setItemInfo(3146, 700.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return player->HealthPercent() <= menu->GetOption("HP to use")->GetFloat() && item->IsReady();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && item->IsTargetInRange(enemy) && enemy->HealthPercent() <= menu->GetOption("Enemy HP")->GetFloat());
						{
							item->CastOnTarget(enemy);
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("Enemy HP", 0.f, 100.f, 65.f);
					menu->AddFloat("HP to use", 0.f, 100.f, 75.f);
				})
	);

		items.push_back(
		Item(sdk, "Hextech GLP 800")
			.setItemInfo(3030, 500.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return player->HealthPercent() <= menu->GetOption("HP to use")->GetFloat() && item->IsReady();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && item->IsTargetInRange(enemy) && enemy->HealthPercent() <= menu->GetOption("Enemy HP")->GetFloat());
						{
							item->CastOnPosition(enemy->GetPosition());
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("Enemy HP", 0.f, 100.f, 65.f);
					menu->AddFloat("HP to use", 0.f, 100.f, 75.f);
				})
	);

		items.push_back(
		Item(sdk, "Ravenous Hydra")
			.setItemInfo(3074, 385.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return item->IsReady() && orbwalking->CanMove(0.1f);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && item->IsTargetInRange(enemy));
						{
							item->CastOnPlayer();
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
				})
	);

		items.push_back(
		Item(sdk, "Tiamat")
			.setItemInfo(3077, 385.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return item->IsReady() && orbwalking->CanMove(0.1f);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && item->IsTargetInRange(enemy));
						{
							item->CastOnPlayer();
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
				})
	);

		items.push_back(
		Item(sdk, "Titanic Hydra")
			.setItemInfo(3748, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return item->IsReady() && orbwalking->CanMove(0.1f);
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && player->GetRealAutoAttackRange(enemy))
						{
							item->CastOnPlayer();
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
				})
	);

		items.push_back(
		Item(sdk, "Youmuu's Ghostblade")
			.setItemInfo(3142, 0.f)
			.setCallbackInfo(
				[&] (IInventoryItem *item, IMenu *menu) -> bool {
					return player->HealthPercent() <= menu->GetOption("HP to use")->GetFloat() && item->IsReady();
				},
				[&](IInventoryItem *item, IMenu *menu) -> void {
					//use the item
					for (auto enemy : sdk->GetEntityList()->GetAllHeros(false, true))
					{
						if (enemy->IsValidTarget() && enemy->HealthPercent() <= menu->GetOption("Enemy HP")->GetFloat() && player->GetRealAutoAttackRange(enemy));
						{
							item->CastOnPlayer();
						}
					}
				})
			.addToMenu(potionsMenu, true, false,
				[&](IMenu *menu) -> void {
					//add any extra menu options here
					menu->AddFloat("Enemy HP", 0.f, 100.f, 65.f);
					menu->AddFloat("HP to use", 0.f, 100.f, 75.f);
				})
	);

	return items;
}
