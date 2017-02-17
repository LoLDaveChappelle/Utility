#pragma once
#include <functional>
#include <vector>
#include "PluginData.h"
#include "PluginSDK.h"

namespace eventmanager {
	class OrbwalkerEventManager
	{
	public:
		static std::function<void(IUnit *)> RegisterBeforeAttackEvent(std::function<void(IUnit *)> func);
		static std::function<void(IUnit *, IUnit *)> RegisterAttackEvent(std::function<void(IUnit *, IUnit *)> func);
		static std::function<void(IUnit *, IUnit *)> RegisterAfterAttackEvent(std::function<void(IUnit *, IUnit *)> func);
		static std::function<void(IUnit *, IUnit *)> RegisterNewTargetEvent(std::function<void(IUnit *, IUnit *)> func);
		static std::function<void(IUnit *)> RegisterNonKillableMinionEvent(std::function<void(IUnit *)> func);
		static std::function<IUnit *()> RegisterFindTargetEvent(std::function<IUnit *()> func);

		static void UnregisterBeforeAttackEvent(std::function<void(IUnit *)> func);
		static void UnregisterAttackEvent(std::function<void(IUnit *, IUnit *)> func);
		static void UnregisterAfterAttackEvent(std::function<void(IUnit *, IUnit *)> func);
		static void UnregisterNewTargetEvent(std::function<void(IUnit *, IUnit *)> func);
		static void UnregisterNonKillableMinionEvent(std::function<void(IUnit *)> func);
		static void UnregisterFindTargetEvent(std::function<IUnit *()> func);

	private:
		OrbwalkerEventManager() {}
	};

	class GameEventManager
	{
	public:
		static std::function<void()> RegisterUpdateEvent(std::function<void()> func);
		static std::function<void()> RegisterEndEvent(std::function<void()> func);
		static std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)> RegisterWndProcEvent(std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)> func);

		static void UnregisterUpdateEvent(std::function<void()> func);
		static void UnregisterEndEvent(std::function<void()> func);
		static void UnregisterWndProcEvent(std::function<bool(HWND Wnd, UINT Message, WPARAM wParam, LPARAM lParam)> func);

	private:
		GameEventManager() {}
	};

	class DrawEventManager
	{
	public:
		static std::function<void()> RegisterRenderEvent(std::function<void()> func);
		static std::function<void()> RegisterRenderBehindHudEvent(std::function<void()> func);
		static std::function<void()> RegisterD3DPresentEvent(std::function<void()> func);
		static std::function<void()> RegisterD3DPreResetEvent(std::function<void()> func);
		static std::function<void()> RegisterD3DPostResetEvent(std::function<void()> func);

		static void UnregisterRenderEvent(std::function<void()> func);
		static void UnregisterRenderBehindHudEvent(std::function<void()> func);
		static void UnregisterD3DPresentEvent(std::function<void()> func);
		static void UnregisterD3DPreResetEvent(std::function<void()> func);
		static void UnregisterD3DPostResetEvent(std::function<void()> func);

	private:
		DrawEventManager() {}
	};

	class UnitEventManager
	{
	public:
		static std::function<void(IUnit *)> RegisterCreateEvent(std::function<void(IUnit *)> func);
		static std::function<void(IUnit *)> RegisterDestroyEvent(std::function<void(IUnit *)> func);
		static std::function<void(IUnit *)> RegisterDeathEvent(std::function<void(IUnit *)> func);
		static std::function<bool(IUnit *, int, Vec3 *, IUnit *)> RegisterIssueOrderEvent(std::function<bool(IUnit *, int, Vec3 *, IUnit *)> func);
		static std::function<bool(int, IUnit *, Vec3 *, Vec3 *)> RegisterPreCastEvent(std::function<bool(int, IUnit *, Vec3 *, Vec3 *)> func);
		static std::function<void(int, Vec3 *, bool *, bool *)> RegisterUpdateChargedSpellEvent(std::function<void(int, Vec3 *, bool *, bool *)> func);
		static std::function<void(CastedSpell const &)> RegisterProcessSpellCastEvent(std::function<void(CastedSpell const &)> func);
		static std::function<void(CastedSpell const &)> RegisterDoCastEvent(std::function<void(CastedSpell const &)> func);
		static std::function<void(InterruptibleSpell const &)> RegisterProcessInterruptibleSpellEvent(std::function<void(InterruptibleSpell const &)> func);
		static std::function<void(GapCloserSpell const &)> RegisterProcessGapCloserSpellEvent(std::function<void(GapCloserSpell const &)> func);
		static std::function<void(IUnit *, void *)> RegisterBuffAddEvent(std::function<void(IUnit *, void *)> func);
		static std::function<void(IUnit *, void *)> RegisterBuffRemoveEvent(std::function<void(IUnit *, void *)> func);
		static std::function<void(IUnit *, int)> RegisterLevelUpEvent(std::function<void(IUnit *, int)> func);
		static std::function<void(UnitDash *)> RegisterDashEvent(std::function<void(UnitDash *)> func);
		static std::function<void(IUnit *)> RegisterEnterVisibilityEvent(std::function<void(IUnit *)> func);
		static std::function<void(IUnit *)> RegisterExitVisibilityEvent(std::function<void(IUnit *)> func);
		static std::function<bool(IUnit *, std::string const)> RegisterPlayAnimationEvent(std::function<bool(IUnit *, std::string const)> func);
		static std::function<bool(IUnit *, std::string const)> RegisterPauseAnimationEvent(std::function<bool(IUnit *, std::string const)> func);

		static void UnregisterCreateEvent(std::function<void(IUnit *)> func);
		static void UnregisterDestroyEvent(std::function<void(IUnit *)> func);
		static void UnregisterDeathEvent(std::function<void(IUnit *)> func);
		static void UnregisterIssueOrderEvent(std::function<bool(IUnit *, int, Vec3 *, IUnit *)> func);
		static void UnregisterPreCastEvent(std::function<bool(int, IUnit *, Vec3 *, Vec3 *)> func);
		static void UnregisterUpdateChargedSpellEvent(std::function<void(int, Vec3 *, bool *, bool *)> func);
		static void UnregisterProcessSpellCastEvent(std::function<void(CastedSpell const &)> func);
		static void UnregisterDoCastEvent(std::function<void(CastedSpell const &)> func);
		static void UnregisterProcessInterruptibleSpellEvent(std::function<void(InterruptibleSpell const &)> func);
		static void UnregisterProcessGapCloserSpellEvent(std::function<void(GapCloserSpell const &)> func);
		static void UnregisterBuffAddEvent(std::function<void(IUnit *, void *)> func);
		static void UnregisterBuffRemoveEvent(std::function<void(IUnit *, void *)> func);
		static void UnregisterLevelUpEvent(std::function<void(IUnit *, int)> func);
		static void UnregisterDashEvent(std::function<void(UnitDash *)> func);
		static void UnregisterEnterVisibilityEvent(std::function<void(IUnit *)> func);
		static void UnregisterExitVisibilityEvent(std::function<void(IUnit *)> func);
		static void UnregisterPlayAnimationEvent(std::function<bool(IUnit *, std::string const)> func);
		static void UnregisterPauseAnimationEvent(std::function<bool(IUnit *, std::string const)> func);

	private:
		UnitEventManager() {}
	};

	void RegisterEvents(IEventManager *eventManager);
	void UnregisterEvents(IEventManager *eventManager);
}
