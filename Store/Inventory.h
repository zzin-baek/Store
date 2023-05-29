#pragma once
#include "header.h"
#include "Items.h"

class Inventory
{
private:
	std::vector<itemInfo> inven;
	itemInfo tempItem;

public:
	Inventory();
	~Inventory();

	void addItems(itemInfo items);
	void showInven();
	int getInvenSize() { return inven.size(); }

	itemInfo sellItems(int index);

};

