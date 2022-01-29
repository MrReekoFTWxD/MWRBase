#ifndef MENU_H
#define MENU_H

enum menuIds
{
	MAIN,
	MENU1,
	MENU2,
	MENU3,
	MENU_PROJECTILE,
	MENU4,


	MENU_COUNT

};
struct clientMenu_t
{
	clientMenu_t();

	int scroll;
	bool isOpen;
	int maxScroll;
	int curMenu;
	bool menuInit;

	std::map<std::string, HECmd*> Huds;


	bool projectile;
	const char* projectileStr;
};

extern clientMenu_t Clients[18];



void BuildHuds(int client);

void UpdateOptions(int client, const std::string& text);
void SwitchMenu(int client, int menu);
void SelectOption(int client);

#endif