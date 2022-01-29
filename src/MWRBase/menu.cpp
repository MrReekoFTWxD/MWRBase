#include "pch.h"
#include "menu.h"

clientMenu_t Clients[18];



void BuildHuds(int client)
{
	if (Clients[client].menuInit)
		return;

	if (!Clients[client].Huds["background"])
		Clients[client].Huds["background"] = createRectangle(client, 200, -3000, 250, 1920, HORZ_SUBLEFT, VERT_SUBTOP, { 0,0,0,150 }, "white", -1);
	
	if (!Clients[client].Huds["LineL"])
		Clients[client].Huds["LineL"] = createRectangle(client, 200, -3000, 2, 1920, HORZ_SUBLEFT, VERT_SUBTOP, { 255,0,0,255 }, "white", 1);
	
	if (!Clients[client].Huds["LineR"])
		Clients[client].Huds["LineR"] = createRectangle(client, 450, -3000, 2, 1920, HORZ_SUBLEFT, VERT_SUBTOP, { 255,0,0,255 }, "white", 1);
	
	if (!Clients[client].Huds["Title"])
		Clients[client].Huds["Title"] = createString(client, "MWR Base", 265, -2950, 1, HE_FONT_HUDBIG, HORZ_SUBLEFT, VERT_SUBTOP, { 255,255,255,255 }, { 255,0,0,50 }, 1);
	
	if (!Clients[client].Huds["Options"])
		Clients[client].Huds["Options"] = createString(client, "", 208, -2880, .8, HE_FONT_BUTTONPROMPT, HORZ_SUBLEFT, VERT_SUBTOP, { 255,255,255,255 }, { 0,0,0,0 }, 0x7FF);

	if (!Clients[client].Huds["scroller"])
		Clients[client].Huds["scroller"] = createRectangle(client, 200, -2880, 250, 12, HORZ_SUBLEFT, VERT_SUBTOP, { 255,0,0,255 }, "white", 1);

	Clients[client].menuInit = false;
}

void UpdateOptions(int client, const std::string& text)
{
	Clients[client].maxScroll = std::count(text.begin(), text.end(), '\n');
	Clients[client].Huds["Options"]->SetLabel(text, HE_FONT_BUTTONPROMPT, .8);
}

void SwitchMenu(int client, int menu)
{
	Clients[client].curMenu = menu;
	Clients[client].scroll = 0;
	Clients[client].Huds["scroller"]->elem->y = 119.f + (Clients[client].scroll * 12.5);

	switch (menu)
	{
	case MAIN: UpdateOptions(client, "Menu1\nMenu2\nMenu3\nProjectiles\nMenu4"); break;

	case MENU1: UpdateOptions(client, "Opt 1\nOpt 2\nOpt 3"); break;
	
	case MENU2: UpdateOptions(client, "Opt 1\nOpt 2\nOpt 3"); break;
	
	case MENU3: UpdateOptions(client, "Opt 1\nOpt 2\nOpt 3"); break;
	
	case MENU_PROJECTILE: UpdateOptions(client, "Shoot Projectiles\nShoot: RPG"); break;
	
	case MENU4: UpdateOptions(client, "Opt 1\nOpt 2\nOpt 3"); break;
	}
}

void SelectOption(int client)
{
	switch (Clients[client].curMenu)
	{
	case MAIN: SwitchMenu(client, Clients[client].scroll + 1); break;

	case MENU1:
		switch (Clients[client].scroll)
		{
		case 0: iclientprintln(client,"Menu1 Opt 1"); break;
		case 1: iclientprintln(client,"Menu1 Opt 2"); break;
		case 2: iclientprintln(client,"Menu1 Opt 3"); break;
		}
		break;
	case MENU2:
		switch (Clients[client].scroll)
		{
		case 0: iclientprintln(client,"Menu2 Opt 1"); break;
		case 1: iclientprintln(client,"Menu2 Opt 2"); break;
		case 2: iclientprintln(client,"Menu2 Opt 3"); break;
		}
		break;
	case MENU3:
		switch (Clients[client].scroll)
		{
		case 0: iclientprintln(client,"Menu3 Opt 1"); break;
		case 1: iclientprintln(client,"Menu3 Opt 2"); break;
		case 2: iclientprintln(client,"Menu3 Opt 3"); break;
		}
		break;


	case MENU_PROJECTILE:
		switch (Clients[client].scroll)
		{
		case 0: Clients[client].projectile = !Clients[client].projectile; iclientprintln(client, Clients[client].projectile?"Shoot Projectile: ^2Enabled" : "Shoot Projectile: ^1Disabled"); break;
		case 1: Clients[client].projectileStr = "h1_rpg_mp"; iclientprintln(client, "Projectile: ^1h1_rpg_mp");  break;
		}
		break;

	case MENU4:
		switch (Clients[client].scroll)
		{
		case 0: iclientprintln(client, "Menu4 Opt 1"); break;
		case 1: iclientprintln(client, "Menu4 Opt 2"); break;
		case 2: iclientprintln(client, "Menu4 Opt 3"); break;
		}
		break;

	}
}

clientMenu_t::clientMenu_t()
{
	this->projectileStr = "h1_rpg_mp";
}
