#pragma once
#include "ICastable.h"
#include <vector>
#include "ICastableBuilder.h"
#include "PluginSDK.h"

class PotionBuilder : public ICastableBuilder
{
public:
	std::vector<ICastable> const &build(IPluginSDK *sdk, IMenu *parentMenu) override;
};

