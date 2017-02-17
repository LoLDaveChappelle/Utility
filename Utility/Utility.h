#pragma once
#include "PluginSDK.h"
#include "ICastable.h"

class Utility
{
public:
	explicit Utility(IPluginSDK *sdk);
	~Utility();

private:
	IPluginSDK *sdk;
	IMenu *root;
	std::vector<ICastable &> castables;
};

