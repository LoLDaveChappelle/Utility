#include "PluginSDK.h"
#include "EventManager.h"
#include "Utility.h"

PluginSetup("Utility");

IEventManager *eventManager = nullptr;
Utility *implementation = nullptr;

PLUGIN_API void OnLoad(IPluginSDK *pluginSDK)
{
	eventManager = pluginSDK->GetEventManager();
	eventmanager::RegisterEvents(eventManager);

	implementation = new Utility(pluginSDK);
}

PLUGIN_API void OnUnload()
{
	eventmanager::UnregisterEvents(eventManager);

	delete implementation;
}
