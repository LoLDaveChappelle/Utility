#pragma once
#include "ICastableBuilder.h"

class OffensiveBuilder : public ICastableBuilder
{
public:
	std::vector<ICastable> const &build(IPluginSDK *sdk, IMenu *parentMenu) override;
};


