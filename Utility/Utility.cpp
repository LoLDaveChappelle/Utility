#include "Utility.h"
#include "lpputils.h"
#include "Item.h"
#include "PotionBuilder.h"
#include "EventManager.h"

Utility::Utility(IPluginSDK* sdk) : sdk(sdk)
{
	this->root = sdk->AddMenu("Utility");

	auto potions = PotionBuilder().build(sdk, this->root);
	this->castables.insert(this->castables.end(), potions.begin(), potions.end());

	eventmanager::GameEventManager::RegisterUpdateEvent([&]() -> void {
		for (ICastable &castable : this->castables)
		{
			if (castable.shouldCast())
			{
				castable.cast();
			}
		}
	});
}

Utility::~Utility()
{
	this->root->Remove();
}
