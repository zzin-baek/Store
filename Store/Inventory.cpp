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
	printf("==== ���� ������ ������ ====\n\n");
	for (auto oIterator = inven.begin(); oIterator != inven.end(); ++oIterator)
	{
		int nIndex = oIterator - inven.begin();

		printf("�κ��丮 ������ �ѹ�: %d\n", nIndex + 1);
		printf("�ڵ� �з�: %d\n", oIterator->nType);
		printf("�̸�: %s\n", oIterator->sName.c_str());
		printf("����: %d\n", oIterator->nPrice);
		printf("Ư¡: %s\n", oIterator->sChar.c_str());
		printf("���ݷ� ���: %d\n", oIterator->nStat);

		cout << "===========================" << endl;
	}
}

itemInfo Inventory::sellItems(int index)
{
	tempItem = inven.at(index - 1);
	inven.erase(inven.begin() + (index - 1));
	
	return tempItem;
}

