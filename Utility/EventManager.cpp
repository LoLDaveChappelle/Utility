#include "EventManager.h"
#include "lpputils.h"

namespace eventmanager
{
	/**
	* OrbwalkerEventManager
	*/
	static std::vector<std::function<void(IUnit *)>> beforeAttackHandlers;
	static std::vector<std::function<void(IUnit *, IUnit *)>> attackHandlers;
	static std::vector<std::function<void(IUnit *, IUnit *)>> afterAttackHandlers;
	static std::vector<std::function<void(IUnit *, IUnit *)>> newTargetHandlers;
	static std::vector<std::function<void(IUnit *)>> nonKillableMinionHandlers;
	static std::vector<std::function<IUnit *()>> findTargetHandlers;

	std::function<void(IUnit *)> OrbwalkerEventManager::RegisterBeforeAttackEvent(std::function<void(IUnit *)> func)
	{
		beforeAttackHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *, IUnit *)> OrbwalkerEventManager::RegisterAttackEvent(std::function<void(IUnit *, IUnit *)> func)
	{
		attackHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *, IUnit *)> OrbwalkerEventManager::RegisterAfterAttackEvent(std::function<void(IUnit *, IUnit *)> func)
	{
		afterAttackHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *, IUnit *)> OrbwalkerEventManager::RegisterNewTargetEvent(std::function<void(IUnit *, IUnit *)> func)
	{
		newTargetHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *)> OrbwalkerEventManager::RegisterNonKillableMinionEvent(std::function<void(IUnit *)> func)
	{
		nonKillableMinionHandlers.push_back(func);

		return func;
	}

	std::function<IUnit *()> OrbwalkerEventManager::RegisterFindTargetEvent(std::function<IUnit *()> func)
	{
		findTargetHandlers.push_back(func);

		return func;
	}

	void OrbwalkerEventManager::UnregisterBeforeAttackEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(beforeAttackHandlers, func);
	}

	void OrbwalkerEventManager::UnregisterAttackEvent(std::function<void(IUnit *, IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(attackHandlers, func);
	}

	void OrbwalkerEventManager::UnregisterAfterAttackEvent(std::function<void(IUnit *, IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(afterAttackHandlers, func);
	}

	void OrbwalkerEventManager::UnregisterNewTargetEvent(std::function<void(IUnit *, IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(newTargetHandlers, func);
	}

	void OrbwalkerEventManager::UnregisterNonKillableMinionEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(nonKillableMinionHandlers, func);
	}

	void OrbwalkerEventManager::UnregisterFindTargetEvent(std::function<IUnit *()> func)
	{
		LPPUtils::RemoveIfExists(findTargetHandlers, func);
	}

	/**
	* GameEventManager
	*/
	static std::vector<std::function<void()>> updateHandlers;
	static std::vector<std::function<void()>> endHandlers;
	static std::vector<std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)>> wndProcHandlers;

	std::function<void()> RegisterUpdateEvent(std::function<void()> func)
	{
		updateHandlers.push_back(func);

		return func;
	}

	std::function<void()> GameEventManager::RegisterEndEvent(std::function<void()> func)
	{
		endHandlers.push_back(func);

		return func;
	}

	std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)> GameEventManager::RegisterWndProcEvent(std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)> func)
	{
		wndProcHandlers.push_back(func);

		return func;
	}

	void GameEventManager::UnregisterUpdateEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(updateHandlers, func);
	}

	void GameEventManager::UnregisterEndEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(endHandlers, func);
	}

	void GameEventManager::UnregisterWndProcEvent(std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)> func)
	{
		LPPUtils::RemoveIfExists(wndProcHandlers, func);
	}

	/**
	* DrawEventManager
	*/
	static std::vector<std::function<void()>> renderHandlers;
	static std::vector<std::function<void()>> renderBehindHudEventHandlers;
	static std::vector<std::function<void()>> D3DPresentEventHandlers;
	static std::vector<std::function<void()>> D3DPreResetEventHandlers;
	static std::vector<std::function<void()>> D3DPostResetEventHandlers;

	std::function<void()> DrawEventManager::RegisterRenderEvent(std::function<void()> func)
	{
		renderHandlers.push_back(func);

		return func;
	}

	std::function<void()> DrawEventManager::RegisterRenderBehindHudEvent(std::function<void()> func)
	{
		renderBehindHudEventHandlers.push_back(func);

		return func;
	}

	std::function<void()> DrawEventManager::RegisterD3DPresentEvent(std::function<void()> func)
	{
		D3DPresentEventHandlers.push_back(func);

		return func;
	}

	std::function<void()> DrawEventManager::RegisterD3DPreResetEvent(std::function<void()> func)
	{
		D3DPreResetEventHandlers.push_back(func);

		return func;
	}

	std::function<void()> DrawEventManager::RegisterD3DPostResetEvent(std::function<void()> func)
	{
		D3DPostResetEventHandlers.push_back(func);

		return func;
	}

	void DrawEventManager::UnregisterRenderEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(renderHandlers, func);
	}

	void DrawEventManager::UnregisterRenderBehindHudEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(renderBehindHudEventHandlers, func);
	}

	void DrawEventManager::UnregisterD3DPresentEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(D3DPresentEventHandlers, func);
	}

	void DrawEventManager::UnregisterD3DPreResetEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(D3DPreResetEventHandlers, func);
	}

	void DrawEventManager::UnregisterD3DPostResetEvent(std::function<void()> func)
	{
		LPPUtils::RemoveIfExists(D3DPostResetEventHandlers, func);
	}

	/**
	 * UnitEventManager
	 */
	static std::vector<std::function<void(IUnit *)>> createHandlers;
	static std::vector<std::function<void(IUnit *)>> destroyHandlers;
	static std::vector<std::function<void(IUnit *)>> deathHandlers;
	static std::vector<std::function<bool(IUnit *, int, Vec3 *, IUnit *)>> issueOrderHandlers;
	static std::vector<std::function<bool(int, IUnit *, Vec3 *, Vec3 *)>> preCastHandlers;
	static std::vector<std::function<void(int, Vec3 *, bool *, bool *)>> updateChargedSpellHandlers;
	static std::vector<std::function<void(CastedSpell const &)>> processSpellCastHandlers;
	static std::vector<std::function<void(CastedSpell const &)>> doCastHandlers;
	static std::vector<std::function<void(InterruptibleSpell const &)>> processInterruptibleSpellHandlers;
	static std::vector<std::function<void(GapCloserSpell const &)>> processGapCloserSpellHandlers;
	static std::vector<std::function<void(IUnit *, void *)>> buffAddHandlers;
	static std::vector<std::function<void(IUnit *, void *)>> buffRemoveHandlers;
	static std::vector<std::function<void(IUnit *, int)>> levelUpHandlers;
	static std::vector<std::function<void(UnitDash *)>> dashHandlers;
	static std::vector<std::function<void(IUnit *)>> enterVisibilityHandlers;
	static std::vector<std::function<void(IUnit *)>> exitVisibilityHandlers;
	static std::vector<std::function<bool(IUnit *, std::string const)>> playAnimationHandlers;
	static std::vector<std::function<bool(IUnit *, std::string const)>> pauseAnimationHandlers;


	std::function<void(IUnit *)> UnitEventManager::RegisterCreateEvent(std::function<void(IUnit *)> func)
	{
		createHandlers.push_back(func);
		
		return func;
	}

	std::function<void(IUnit *)> UnitEventManager::RegisterDestroyEvent(std::function<void(IUnit *)> func)
	{
		destroyHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *)> UnitEventManager::RegisterDeathEvent(std::function<void(IUnit *)> func)
	{
		deathHandlers.push_back(func);

		return func;
	}

	std::function<bool(IUnit *, int, Vec3 *, IUnit *)> UnitEventManager::RegisterIssueOrderEvent(std::function<bool(IUnit *, int, Vec3 *, IUnit *)> func)
	{
		issueOrderHandlers.push_back(func);

		return func;
	}

	std::function<bool(int, IUnit *, Vec3 *, Vec3 *)> UnitEventManager::RegisterPreCastEvent(std::function<bool(int, IUnit *, Vec3 *, Vec3 *)> func)
	{
		preCastHandlers.push_back(func);

		return func;
	}

	std::function<void(int, Vec3 *, bool *, bool *)> UnitEventManager::RegisterUpdateChargedSpellEvent(std::function<void(int, Vec3 *, bool *, bool *)> func)
	{
		updateChargedSpellHandlers.push_back(func);

		return func;
	}

	std::function<void(CastedSpell const &)> UnitEventManager::RegisterProcessSpellCastEvent(std::function<void(CastedSpell const &)> func)
	{
		processSpellCastHandlers.push_back(func);

		return func;
	}

	std::function<void(CastedSpell const &)> UnitEventManager::RegisterDoCastEvent(std::function<void(CastedSpell const &)> func)
	{
		doCastHandlers.push_back(func);

		return func;
	}

	std::function<void(InterruptibleSpell const &)> UnitEventManager::RegisterProcessInterruptibleSpellEvent(std::function<void(InterruptibleSpell const &)> func)
	{
		processInterruptibleSpellHandlers.push_back(func);

		return func;
	}

	std::function<void(GapCloserSpell const &)> UnitEventManager::RegisterProcessGapCloserSpellEvent(std::function<void(GapCloserSpell const &)> func)
	{
		processGapCloserSpellHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *, void *)> UnitEventManager::RegisterBuffAddEvent(std::function<void(IUnit *, void *)> func)
	{
		buffAddHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *, void *)> UnitEventManager::RegisterBuffRemoveEvent(std::function<void(IUnit *, void *)> func)
	{
		buffRemoveHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *, int)> UnitEventManager::RegisterLevelUpEvent(std::function<void(IUnit *, int)> func)
	{
		levelUpHandlers.push_back(func);

		return func;
	}

	std::function<void(UnitDash *)> UnitEventManager::RegisterDashEvent(std::function<void(UnitDash *)> func)
	{
		dashHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *)> UnitEventManager::RegisterEnterVisibilityEvent(std::function<void(IUnit *)> func)
	{
		enterVisibilityHandlers.push_back(func);

		return func;
	}

	std::function<void(IUnit *)> UnitEventManager::RegisterExitVisibilityEvent(std::function<void(IUnit *)> func)
	{
		exitVisibilityHandlers.push_back(func);

		return func;
	}

	std::function<bool(IUnit*, std::string const)> UnitEventManager::RegisterPlayAnimationEvent(std::function<bool(IUnit*, std::string const)> func)
	{
		playAnimationHandlers.push_back(func);

		return func;
	}

	std::function<bool(IUnit*, std::string const)> UnitEventManager::RegisterPauseAnimationEvent(std::function<bool(IUnit*, std::string const)> func)
	{
		pauseAnimationHandlers.push_back(func);

		return func;
	}

	void UnitEventManager::UnregisterCreateEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(createHandlers, func);
	}

	void UnitEventManager::UnregisterDestroyEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(destroyHandlers, func);
	}

	void UnitEventManager::UnregisterDeathEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(deathHandlers, func);
	}

	void UnitEventManager::UnregisterIssueOrderEvent(std::function<bool(IUnit *, int, Vec3 *, IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(issueOrderHandlers, func);
	}

	void UnitEventManager::UnregisterPreCastEvent(std::function<bool(int, IUnit *, Vec3 *, Vec3 *)> func)
	{
		LPPUtils::RemoveIfExists(preCastHandlers, func);
	}

	void UnitEventManager::UnregisterUpdateChargedSpellEvent(std::function<void(int, Vec3 *, bool *, bool *)> func)
	{
		LPPUtils::RemoveIfExists(updateChargedSpellHandlers, func);
	}

	void UnitEventManager::UnregisterProcessSpellCastEvent(std::function<void(CastedSpell const &)> func)
	{
		LPPUtils::RemoveIfExists(processSpellCastHandlers, func);
	}

	void UnitEventManager::UnregisterDoCastEvent(std::function<void(CastedSpell const &)> func)
	{
		LPPUtils::RemoveIfExists(doCastHandlers, func);
	}

	void UnitEventManager::UnregisterProcessInterruptibleSpellEvent(std::function<void(InterruptibleSpell const &)> func)
	{
		LPPUtils::RemoveIfExists(processInterruptibleSpellHandlers, func);
	}

	void UnitEventManager::UnregisterProcessGapCloserSpellEvent(std::function<void(GapCloserSpell const &)> func)
	{
		LPPUtils::RemoveIfExists(processGapCloserSpellHandlers, func);
	}

	void UnitEventManager::UnregisterBuffAddEvent(std::function<void(IUnit *, void *)> func)
	{
		LPPUtils::RemoveIfExists(buffAddHandlers, func);
	}

	void UnitEventManager::UnregisterBuffRemoveEvent(std::function<void(IUnit *, void *)> func)
	{
		LPPUtils::RemoveIfExists(buffRemoveHandlers, func);
	}

	void UnitEventManager::UnregisterLevelUpEvent(std::function<void(IUnit *, int)> func)
	{
		LPPUtils::RemoveIfExists(levelUpHandlers, func);
	}

	void UnitEventManager::UnregisterDashEvent(std::function<void(UnitDash *)> func)
	{
		LPPUtils::RemoveIfExists(dashHandlers, func);
	}

	void UnitEventManager::UnregisterEnterVisibilityEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(enterVisibilityHandlers, func);
	}

	void UnitEventManager::UnregisterExitVisibilityEvent(std::function<void(IUnit *)> func)
	{
		LPPUtils::RemoveIfExists(exitVisibilityHandlers, func);
	}

	void UnitEventManager::UnregisterPlayAnimationEvent(std::function<bool(IUnit*, std::string const)> func)
	{
		LPPUtils::RemoveIfExists(playAnimationHandlers, func);
	}

	void UnitEventManager::UnregisterPauseAnimationEvent(std::function<bool(IUnit*, std::string const)> func)
	{
		LPPUtils::RemoveIfExists(pauseAnimationHandlers, func);
	}

	PLUGIN_EVENT(void) OnOrbwalkBeforeAttack(IUnit *target)
	{
		for (auto function : beforeAttackHandlers)
		{
			function(target);
		}
	}

	PLUGIN_EVENT(void) OnOrbwalkAttack(IUnit *source, IUnit *target)
	{
		for (auto function : attackHandlers)
		{
			function(source, target);
		}
	}

	PLUGIN_EVENT(void) OnOrbwalkAfterAttack(IUnit *source, IUnit *target)
	{
		for (auto function : afterAttackHandlers)
		{
			function(source, target);
		}
	}

	PLUGIN_EVENT(void) OnOrbwalkTargetChange(IUnit *oldTarget, IUnit *newTarget)
	{
		for (auto function : newTargetHandlers)
		{
			function(oldTarget, newTarget);
		}
	}

	PLUGIN_EVENT(void) OnOrbwalkOrbwalkNonKillableMinion(IUnit *nonKillableMinion)
	{
		for (auto function : nonKillableMinionHandlers)
		{
			function(nonKillableMinion);
		}
	}

	PLUGIN_EVENT(IUnit *) OnOrbwalkFindTarget()
	{
		IUnit *target = nullptr;

		for (auto function : findTargetHandlers)
		{
			auto ret = function();

			if (ret != nullptr && target == nullptr)
			{
				target = nullptr;
			}
		}

		return target;
	}

	PLUGIN_EVENT(void) OnGameUpdate()
	{
		for (auto function : updateHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(void) OnGameEnd()
	{
		for (auto function : endHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(bool) OnGameWndProc(HWND wnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		auto ret = true;

		for (auto function : wndProcHandlers)
		{
			auto r = function(wnd, message, wParam, lParam);

			if (!r && ret)
			{
				ret = false;
			}
		}

		return ret;
	}

	PLUGIN_EVENT(void) OnDrawRender()
	{
		for (auto function : renderHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(void) OnDrawRenderBehindHud()
	{
		for (auto function : renderBehindHudEventHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(void) OnDrawRenderD3DPresent()
	{
		for (auto function : D3DPresentEventHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(void) OnDrawRenderD3DPreReset()
	{
		for (auto function : D3DPreResetEventHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(void) OnDrawRenderD3DPostReset()
	{
		for (auto function : D3DPostResetEventHandlers)
		{
			function();
		}
	}

	PLUGIN_EVENT(void) OnUnitCreate(IUnit *unit)
	{
		for (auto function : createHandlers)
		{
			function(unit);
		}
	}

	PLUGIN_EVENT(void) OnUnitDestroy(IUnit *unit)
	{
		for (auto function : destroyHandlers)
		{
			function(unit);
		}
	}

	PLUGIN_EVENT(void) OnUnitDeath(IUnit *unit)
	{
		for (auto function : deathHandlers)
		{
			function(unit);
		}
	}

	PLUGIN_EVENT(bool) OnUnitIssueOrder(IUnit *source, int orderId, Vec3 *pos, IUnit *target)
	{
		auto process = true;

		for (auto function : issueOrderHandlers)
		{
			auto ret = function(source, orderId, pos, target);

			if (!ret && process)
			{
				process = false;
			}
		}

		return process;
	}

	PLUGIN_EVENT(bool) OnUnitPreCast(int slot, IUnit *target, Vec3 *start, Vec3 *end)
	{
		auto process = true;

		for (auto function : preCastHandlers)
		{
			auto ret = function(slot, target, start, end);

			if (!ret && process)
			{
				process = false;
			}
		}

		return process;
	}

	PLUGIN_EVENT(void) OnUnitUpdateChargedSpell(int slot, Vec3 *position, bool *releaseCast, bool *triggerEvent)
	{
		for (auto function : updateChargedSpellHandlers)
		{
			function(slot, position, releaseCast, triggerEvent);
		}
	}

	PLUGIN_EVENT(void) OnUnitProcessSpellCast(CastedSpell const &spell)
	{
		for (auto function : processSpellCastHandlers)
		{
			function(spell);
		}
	}

	PLUGIN_EVENT(void) OnUnitDoCast(CastedSpell const &spell)
	{
		for (auto function : doCastHandlers)
		{
			function(spell);
		}
	}

	PLUGIN_EVENT(void) OnUnitProcessInterruptableSpellCast(InterruptibleSpell const &spell)
	{
		for (auto function : processInterruptibleSpellHandlers)
		{
			function(spell);
		}
	}

	PLUGIN_EVENT(void) OnUnitProcessGapCloserSpellCast(GapCloserSpell const &spell)
	{
		for (auto function : processGapCloserSpellHandlers)
		{
			function(spell);
		}
	}

	PLUGIN_EVENT(void) OnUnitBuffAdd(IUnit *source, void *buffData)
	{
		for (auto function : buffAddHandlers)
		{
			function(source, buffData);
		}
	}

	PLUGIN_EVENT(void) OnUnitBuffRemove(IUnit *source, void *buffData)
	{
		for (auto function : buffRemoveHandlers)
		{
			function(source, buffData);
		}
	}

	PLUGIN_EVENT(void) OnUnitLevelUp(IUnit *source, int newLevel)
	{
		for (auto function : levelUpHandlers)
		{
			function(source, newLevel);
		}
	}

	PLUGIN_EVENT(void) OnUnitDash(UnitDash *dashArgs)
	{
		for (auto function : dashHandlers)
		{
			function(dashArgs);
		}
	}

	PLUGIN_EVENT(void) OnUnitEnterVisibility(IUnit *unit)
	{
		for (auto function : enterVisibilityHandlers)
		{
			function(unit);
		}
	}

	PLUGIN_EVENT(void) OnUnitExitVisibility(IUnit *unit)
	{
		for (auto function : exitVisibilityHandlers)
		{
			function(unit);
		}
	}

	PLUGIN_EVENT(bool) OnUnitPlayAnimation(IUnit *source, std::string const animationId)
	{
		auto process = true;

		for (auto function : playAnimationHandlers)
		{
			auto ret = function(source, animationId);

			if (!ret && process)
			{
				process = false;
			}
		}

		return process;
	}

	PLUGIN_EVENT(bool) OnUnitPauseAnimation(IUnit *source, std::string const animationId)
	{
		auto process = true;

		for (auto function : pauseAnimationHandlers)
		{
			auto ret = function(source, animationId);

			if (!ret && process)
			{
				process = false;
			}
		}

		return process;
	}

	void RegisterEvents(IEventManager *eventManager)
	{
		//Orbwalker Events
		eventManager->AddEventHandler(kEventOrbwalkBeforeAttack, OnOrbwalkBeforeAttack);
		eventManager->AddEventHandler(kEventOrbwalkOnAttack, OnOrbwalkAttack);
		eventManager->AddEventHandler(kEventOrbwalkAfterAttack, OnOrbwalkAfterAttack);
		eventManager->AddEventHandler(kEventOrbwalkTargetChange, OnOrbwalkAfterAttack);
		eventManager->AddEventHandler(kEventOrbwalkNonKillableMinion, OnOrbwalkOrbwalkNonKillableMinion);
		eventManager->AddEventHandler(kEventOrbwalkFindTarget, OnOrbwalkFindTarget);

		//Game Events
		eventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
		eventManager->AddEventHandler(kEventOnGameEnd, OnGameEnd);
		eventManager->AddEventHandler(kEventOnWndProc, OnGameWndProc);

		//Draw Events
		eventManager->AddEventHandler(kEventOnRender, OnDrawRender);
		eventManager->AddEventHandler(kEventOnRenderBehindHud, OnDrawRenderBehindHud);
		eventManager->AddEventHandler(kEventOnD3DPresent, OnDrawRenderD3DPresent);
		eventManager->AddEventHandler(kEventOnD3DPreReset, OnDrawRenderD3DPreReset);
		eventManager->AddEventHandler(kEventOnD3DPostReset, OnDrawRenderD3DPostReset);

		//Unit Events
		eventManager->AddEventHandler(kEventOnCreateObject, OnUnitCreate);
		eventManager->AddEventHandler(kEventOnDestroyObject, OnUnitDestroy);
		eventManager->AddEventHandler(kEventOnUnitDeath, OnUnitDeath);
		eventManager->AddEventHandler(kEventOnIssueOrder, OnUnitIssueOrder);
		eventManager->AddEventHandler(kEventOnPreCast, OnUnitPreCast);
		eventManager->AddEventHandler(kEventOnUpdateChargedSpell, OnUnitUpdateChargedSpell);
		eventManager->AddEventHandler(kEventOnSpellCast, OnUnitProcessSpellCast);
		eventManager->AddEventHandler(kEventOnDoCast, OnUnitDoCast);
		eventManager->AddEventHandler(kEventOnInterruptible, OnUnitProcessInterruptableSpellCast);
		eventManager->AddEventHandler(kEventOnGapCloser, OnUnitProcessGapCloserSpellCast);
		eventManager->AddEventHandler(kEventOnBuffAdd, OnUnitBuffAdd);
		eventManager->AddEventHandler(kEventOnBuffRemove, OnUnitBuffRemove);
		eventManager->AddEventHandler(kEventOnLevelUp, OnUnitLevelUp);
		eventManager->AddEventHandler(kEventOnDash, OnUnitDash);
		eventManager->AddEventHandler(kEventOnEnterVisible, OnUnitEnterVisibility);
		eventManager->AddEventHandler(kEventOnExitVisible, OnUnitExitVisibility);
		eventManager->AddEventHandler(kEventOnPlayAnimation, OnUnitPlayAnimation);
		eventManager->AddEventHandler(kEventOnPauseAnimation, OnUnitPauseAnimation);
	}

	void UnregisterEvents(IEventManager *eventManager)
	{
		//Orbwalker Events
		eventManager->RemoveEventHandler(kEventOrbwalkBeforeAttack, OnOrbwalkBeforeAttack);
		eventManager->RemoveEventHandler(kEventOrbwalkOnAttack, OnOrbwalkAttack);
		eventManager->RemoveEventHandler(kEventOrbwalkAfterAttack, OnOrbwalkAfterAttack);
		eventManager->RemoveEventHandler(kEventOrbwalkTargetChange, OnOrbwalkAfterAttack);
		eventManager->RemoveEventHandler(kEventOrbwalkNonKillableMinion, OnOrbwalkOrbwalkNonKillableMinion);
		eventManager->RemoveEventHandler(kEventOrbwalkFindTarget, OnOrbwalkFindTarget);

		//Game Events
		eventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
		eventManager->RemoveEventHandler(kEventOnGameEnd, OnGameEnd);
		eventManager->RemoveEventHandler(kEventOnWndProc, OnGameWndProc);

		//Draw Events
		eventManager->RemoveEventHandler(kEventOnRender, OnDrawRender);
		eventManager->RemoveEventHandler(kEventOnRenderBehindHud, OnDrawRenderBehindHud);
		eventManager->RemoveEventHandler(kEventOnD3DPresent, OnDrawRenderD3DPresent);
		eventManager->RemoveEventHandler(kEventOnD3DPreReset, OnDrawRenderD3DPreReset);
		eventManager->RemoveEventHandler(kEventOnD3DPostReset, OnDrawRenderD3DPostReset);

		//Unit Events
		eventManager->RemoveEventHandler(kEventOnCreateObject, OnUnitCreate);
		eventManager->RemoveEventHandler(kEventOnDestroyObject, OnUnitDestroy);
		eventManager->RemoveEventHandler(kEventOnUnitDeath, OnUnitDeath);
		eventManager->RemoveEventHandler(kEventOnIssueOrder, OnUnitIssueOrder);
		eventManager->RemoveEventHandler(kEventOnPreCast, OnUnitPreCast);
		eventManager->RemoveEventHandler(kEventOnUpdateChargedSpell, OnUnitUpdateChargedSpell);
		eventManager->RemoveEventHandler(kEventOnSpellCast, OnUnitProcessSpellCast);
		eventManager->RemoveEventHandler(kEventOnDoCast, OnUnitDoCast);
		eventManager->RemoveEventHandler(kEventOnInterruptible, OnUnitProcessInterruptableSpellCast);
		eventManager->RemoveEventHandler(kEventOnGapCloser, OnUnitProcessGapCloserSpellCast);
		eventManager->RemoveEventHandler(kEventOnBuffAdd, OnUnitBuffAdd);
		eventManager->RemoveEventHandler(kEventOnBuffRemove, OnUnitBuffRemove);
		eventManager->RemoveEventHandler(kEventOnLevelUp, OnUnitLevelUp);
		eventManager->RemoveEventHandler(kEventOnDash, OnUnitDash);
		eventManager->RemoveEventHandler(kEventOnEnterVisible, OnUnitEnterVisibility);
		eventManager->RemoveEventHandler(kEventOnExitVisible, OnUnitExitVisibility);
		eventManager->RemoveEventHandler(kEventOnPlayAnimation, OnUnitPlayAnimation);
		eventManager->RemoveEventHandler(kEventOnPauseAnimation, OnUnitPauseAnimation);
	}
}
