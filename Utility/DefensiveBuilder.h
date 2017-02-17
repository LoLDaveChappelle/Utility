#pragma once
#include "ICastableBuilder.h"

class DefensiveBuilder : public ICastableBuilder
{
public:
	std::vector<ICastable> const &build(IPluginSDK *sdk, IMenu *parentMenu) override;
};


