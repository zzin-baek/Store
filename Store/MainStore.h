#pragma once
#include "Items.h"
#include "Weapon.h"
#include "Accessories.h"
#include "Portion.h"
#include "Shield.h"
#include "header.h"
#include "Inventory.h"
#include "Player.h"

class MainStore
{
private:
	Items* weapon;
	Items* acc;
	Items* shield;
	Items* portion;

	Player* player;
	Inventory* inven;

	itemInfo saved[4];

public:
	MainStore();
	~MainStore();

	inline void selectMenu();
	inline void selectItem();
	inline void buying();
	inline void sell();
	void usedItem();
	void selectUse();
	void goStore();
};

