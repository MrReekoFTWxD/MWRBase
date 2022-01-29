// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

/*

Everyone get access to the menu, if want only some people to have it need to make a auth system

Current Controls:
	Open/Back/Close: Knife
	Scroll Up: Shoot
	Scroll Down: ADS
	Select: Jump


clientMenu_t struct inside of menu.h
is where how im handling all client related variables 

*/

void VM_Notify_f(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue* top)
{
	if (!CL_IsLocalClientInGame(0))
	{
		for (int i = 0; i <= 17; i++)
		{
			Clients[i].menuInit = false;
			Clients[i].Huds.clear();
		}

		return VM_Notify(notifyListOwnerId, stringValue, top);
	}
	
	const char* notify = SL_ConvertToString(stringValue);
	int entNum = Scr_GetSelf(notifyListOwnerId);

	if (!strcmp(notify, "player_spawned"))
	{
		entNum = Scr_GetSelf(top->u.pointerValue);
		Cmd_ResgisterNotification(entNum, "+melee_zoom", "MENU_KNIFE");
		Cmd_ResgisterNotification(entNum, "+speed_throw", "MENU_DOWN");
		Cmd_ResgisterNotification(entNum, "+attack", "MENU_UP");
		Cmd_ResgisterNotification(entNum, "+gostand", "MENU_SELECT");

		BuildHuds(entNum);
	}

	if (!strcmp(notify, "weapon_fired"))
	{
		if (Clients[entNum].projectile)
		{
			vec3_t start = AnglesToForward(PlayerCmd_GetEye(entNum), g_entities[entNum].viewAngles, 30);
			vec3_t end = AnglesToForward(PlayerCmd_GetEye(entNum), g_entities[entNum].viewAngles, 9999);

			Scr_MagicBullet("h1_rpg_mp", start, end);
		}
	}

	if (!strcmp(notify, "MENU_SELECT"))
	{
		if (Clients[entNum].isOpen)
			SelectOption(entNum);
	}
	if (!strcmp(notify, "MENU_DOWN"))
	{
		if (Clients[entNum].isOpen)
		{
			Clients[entNum].scroll++;
			if (Clients[entNum].scroll > Clients[entNum].maxScroll)
				Clients[entNum].scroll = Clients[entNum].maxScroll;

			if (Clients[entNum].Huds["scroller"])
				Clients[entNum].Huds["scroller"]->elem->y = 119.f + (Clients[entNum].scroll * 12.5);
		}
	}
	if (!strcmp(notify, "MENU_UP"))
	{
		if (Clients[entNum].isOpen)
		{
			Clients[entNum].scroll--;
			if (Clients[entNum].scroll < 0)
				Clients[entNum].scroll = 0;

			if (Clients[entNum].Huds["scroller"])
				Clients[entNum].Huds["scroller"]->elem->y = 119.f + (Clients[entNum].scroll * 12.5);
		}
	}

	if (!strcmp(notify, "MENU_KNIFE"))
	{
		if (Clients[entNum].Huds.size() > 0)
		{
			if (Clients[entNum].curMenu > MAIN)
			{
				SwitchMenu(entNum, MAIN);
			}
			else
			{
				Clients[entNum].isOpen = !Clients[entNum].isOpen;
				if (Clients[entNum].isOpen)
				{
					SwitchMenu(entNum, MAIN);
					Clients[entNum].Huds["background"]->MoveOverTime(250, 200, 0);
					Clients[entNum].Huds["LineL"]->MoveOverTime(250, 200, 0);
					Clients[entNum].Huds["LineR"]->MoveOverTime(250, 450, 0);
					Clients[entNum].Huds["Title"]->MoveOverTime(250, 265, 50);
					Clients[entNum].Huds["Options"]->MoveOverTime(250, 208, 120);
					Clients[entNum].Huds["scroller"]->MoveOverTime(250, 200, 119);
				}
				else
				{
					Clients[entNum].Huds["background"]->MoveOverTime(250, 200, -3000);
					Clients[entNum].Huds["LineL"]->MoveOverTime(250, 200, -3000);
					Clients[entNum].Huds["LineR"]->MoveOverTime(250, 450, -3000);
					Clients[entNum].Huds["Title"]->MoveOverTime(250, 265, -2950);
					Clients[entNum].Huds["Options"]->MoveOverTime(250, 208, -2880);
					Clients[entNum].Huds["scroller"]->MoveOverTime(250, 200, -2880);
				}
			}
		}
	}

	VM_Notify(notifyListOwnerId, stringValue, top);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		if (!AllocConsole())
			return false;

		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);
		freopen_s(&f, "CONOUT$", "w", stderr);

		DetourTransactionBegin();
		DetourAttach(&(PVOID&)VM_Notify, VM_Notify_f);
		DetourTransactionCommit();
	}

	if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		if (!FreeConsole())
			return false;

		fclose(stdout);
		fclose(stderr);

		for (int i = 0; i <= 17; i++)
			for (auto huds : Clients[i].Huds)
				huds.second->FreeElem();
	



		DetourTransactionBegin();
		DetourDetach(&(PVOID&)VM_Notify, VM_Notify_f);
		DetourTransactionCommit();
	}

	return true;
}

