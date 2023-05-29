#pragma once
#include "Items.h"

class Shield : public Items
{
private:
	itemInfo shield[3];

public:
	Shield();
	~Shield();

	void showItems();
	int selling(int index);
	void restock(int index) { shield[index - 1].nCount += 1; }
	itemInfo getInfo(int index) { return shield[index - 1]; }
	int getPrice(int index) { return shield[index - 1].nPrice; }
};

