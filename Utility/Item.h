#pragma once
#include "ICastable.h"
#include "PluginSDK.h"
#include <unordered_map>

class Item : public ICastable
{
public:
	explicit Item(IPluginSDK *sdk, std::string name) : sdk(sdk), name(name)
	{
	}

	Item &setItemInfo(int id, float range)
	{
		this->sdk->CreateItemForId(id, range);

		return *this;
	}

	Item &setCallbackInfo(std::function<bool(IInventoryItem *item, IMenu *menu)> const &shouldUse, std::function<void(IInventoryItem *item, IMenu *menu)> const &use)
	{
		this->shouldUseFunc = shouldUse;
		this->useFunc = use;

		return *this;
	}

	Item &addToMenu(IMenu *parent, bool defaultValue, bool defaultUseInCombo, std::function<void(IMenu *menu)> extraMenuItems = nullptr)
	{
		this->menu = parent->AddMenu(this->name.c_str());

		parent->CheckBox("Enabled", defaultValue);
		parent->CheckBox("Use In Combo", defaultUseInCombo);

		if (extraMenuItems != nullptr)
		{
			extraMenuItems(this->menu);
		}

		return *this;
	}


	std::string getName() const override
	{
		return this->name;
	}

	bool shouldCast() const override
	{
		static auto orbwalking = sdk->GetOrbwalking();

		return this->menu->GetOption("Enabled")->Enabled()
			&& (!this->menu->GetOption("Enabled")->Enabled()
				|| orbwalking->GetOrbwalkingMode() == kModeCombo)
			&& this->shouldUseFunc(this->item, this->menu);
	}

	void cast() const override 
	{
		return this->useFunc(this->item, this->menu);
	}

private:
	IPluginSDK *sdk = nullptr;
	std::string name;

	IInventoryItem *item = nullptr;

	std::function<bool(IInventoryItem *item, IMenu *menu)> shouldUseFunc;
	std::function<void(IInventoryItem *item, IMenu *menu)> useFunc;

	IMenu *menu = nullptr;
};