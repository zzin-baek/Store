#pragma once
#include "Items.h"

class Accessories : public Items
{
private:
	itemInfo acc[3];

public:
	Accessories();
	~Accessories();

	void showItems();
	int selling(int index);
	void restock(int index) { acc[index - 1].nCount += 1; }
	itemInfo getInfo(int index) { return acc[index - 1]; }
	int getPrice(int index) { return acc[index - 1].nPrice; }
};

