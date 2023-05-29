#pragma once
#include "Items.h"

class Portion : public Items
{
private:
	itemInfo portion[3];

public:
	Portion();
	~Portion();

	void showItems();
	int selling(int index);
	void restock(int index) { portion[index - 1].nCount += 1; }
	itemInfo getInfo(int index) { return portion[index - 1]; }
	int getPrice(int index) { return portion[index - 1].nPrice; }
};

