#include "Items.h"

Items::Items()
{
	p = new Player;
	//inven = new Inventory;
}

Items::~Items()
{
	delete p;
	//delete inven;
}

void Items::showItems()
{
}

int Items::selling(int index)
{
	return 0;
}

itemInfo Items::getInfo(int index)
{
	return itemInfo();
}
