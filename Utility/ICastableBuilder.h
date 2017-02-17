#pragma once
#include <vector>
#include "ICastable.h"
#include "PluginSDK.h"

class ICastableBuilder
{
public:
	virtual ~ICastableBuilder() = default;
	virtual std::vector<ICastable> const &build(IPluginSDK *sdk, IMenu *parentMenu) = 0;
};
