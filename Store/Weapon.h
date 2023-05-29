#pragma once
#include "Items.h"

class Weapon : public Items
{
private:
	itemInfo weapon[5];

public:
	Weapon();
	~Weapon();

	void showItems();
	int selling(int index);
	void restock(int index) { weapon[index - 1].nCount += 1; }
	itemInfo getInfo(int index) { return weapon[index - 1]; }
	int getPrice(int index) { return weapon[index - 1].nPrice; }
};

