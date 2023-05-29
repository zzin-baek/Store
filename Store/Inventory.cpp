#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::addItems(itemInfo items)
{
	inven.push_back(items);
}

void Inventory::showInven()
{
	//system("cls");
	printf("==== 현재 보유한 아이템 ====\n\n");
	for (auto oIterator = inven.begin(); oIterator != inven.end(); ++oIterator)
	{
		int nIndex = oIterator - inven.begin();

		printf("인벤토리 아이템 넘버: %d\n", nIndex + 1);
		printf("코드 분류: %d\n", oIterator->nType);
		printf("이름: %s\n", oIterator->sName.c_str());
		printf("가격: %d\n", oIterator->nPrice);
		printf("특징: %s\n", oIterator->sChar.c_str());
		printf("공격력 상승: %d\n", oIterator->nStat);

		cout << "===========================" << endl;
	}
}

itemInfo Inventory::sellItems(int index)
{
	tempItem = inven.at(index - 1);
	inven.erase(inven.begin() + (index - 1));
	
	return tempItem;
}

