#pragma once
#include "header.h"
#include "Player.h"

enum itemType
{
	WEAPON = 1,
	SHIELD,
	ACC,
	PORTION
};

struct itemInfo
{
	int nType;
	int nNum;
	std::string sName;
	int nPrice;
	std::string sChar;
	int nStat;
	int nCount;
};

class Items
{
protected:
	itemInfo items;
	Player* p;

public:
	Items();
	~Items();

	inline void printLine() { cout << "===============================" << endl; }
	virtual void showItems();
	virtual int selling(int index);
	virtual void restock(int index) {}
	virtual itemInfo getInfo(int index);
	virtual int getPrice(int index) { return 0; }

};

