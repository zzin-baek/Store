#include "MainStore.h"

MainStore::MainStore()
{
	weapon = new Weapon;
	acc = new Accessories;
	shield = new Shield;
	portion = new Portion;
	player = new Player;
	inven = new Inventory;

}

MainStore::~MainStore()
{
	delete weapon;
	delete acc;
	delete shield;
	delete portion;
	delete player;
	delete inven;
}

void MainStore::selectMenu()
{
	printf("��--------------------------------��\n");
	printf("��       ������ �Ͻðڽ��ϱ�?     ��\n");
	printf("��--------------------------------��\n");
	printf("1.����  2.�κ��丮(�Ǹ�)  3.�κ��丮\n");

}

inline void MainStore::selectItem()
{
	system("cls");
	printf("��--------------------------------��\n");
	printf("��       ���ϴ� ������ ����       ��\n");
	printf("��--------------------------------��\n");
	printf("1. ���� 2. �� 3. �Ǽ����� 4. ����");

}

inline void MainStore::buying()
{
	cout << "���� �����Ӵ�: " << player->getMoney() << "��" << endl;
	cout << "���Ͻô� �������� ��ȣ�� �Է����ּ���(���ư��� ������ 0)" << endl;
	cout << "�� ";
}

inline void MainStore::sell()
{
	cout << "���� �����Ӵ�: " << player->getMoney() << "��" << endl;
	cout << "�Ǹ��Ͻ� �������� ��ȣ�� �Է����ּ���(���ư��� ������ 0)" << endl;
	cout << "�� ";
}

void MainStore::usedItem()
{
	cout << "----------------------------------" << endl;
	cout << "���� ����: " << player->getUsedWeapon() << endl;
	cout << "���� ��: " << player->getUsedShield() << endl;
	cout << "���� �Ǽ�����: " << player->getUsedAcc() << endl;
	cout << "���� ����: " << player->getUsedPortion() << endl;
	cout << "----------------------------------" << endl;

}

void MainStore::selectUse()
{
	cout << "�����ϰ��� �ϴ� ������ ��ȣ�� �Է����ּ���" << endl;
	cout << "�� ";
}

void MainStore::goStore()
{
	int key;
	int buy = 0;
	int sellNum = 0;
	int use = 0;
	while (!_kbhit())
	{
		selectMenu();
		key = _getch();
		if (key == 49)
		{
			selectItem();
			key = _getch();
			if (key == 49)
			{
				while (1)
				{
					weapon->showItems();
					buying();
					cin >> buy;
					if (buy == 0)
						break;
					else if (buy > 5)
					{
						printf("�߸��� �Է��Դϴ�.\n");
						Sleep(1000);
						continue;
					}
					else
					{
						if (player->getMoney() < weapon->getPrice(buy))
						{
							printf("���� �����մϴ�.\n");
							Sleep(1000);
							continue;
						}
						else 
						{
							if (weapon->selling(buy))
							{
								inven->addItems(weapon->getInfo(buy));
								player->setMoney(player->getMoney() - weapon->getPrice(buy));
							}
						}
					}
					Sleep(1000);
				}
			}
			else if (key == 50)
			{
				while(1)
				{
					shield->showItems();
					buying();
					cin >> buy;
					if (buy == 0)
						break;
					else if (buy > 3)
					{
						printf("�߸��� �Է��Դϴ�.\n");
						Sleep(1000);
						continue;
					}
					else
					{
						if (player->getMoney() < shield->getPrice(buy))
						{
							printf("���� �����մϴ�.\n");
							Sleep(1000);
							continue;
						}
						else
						{
							if (shield->selling(buy))
							{
								inven->addItems(shield->getInfo(buy));
								player->setMoney(player->getMoney() - shield->getPrice(buy));
							}
						}
					}
					Sleep(1000);
				}

			}
			else if (key == 51)
			{
				while (1)
				{
					acc->showItems();
					buying();
					cin >> buy;
					if (buy == 0)
						break;
					else if (buy > 3)
					{
						printf("�߸��� �Է��Դϴ�.\n");
						Sleep(1000);
						continue;
					}
					else
					{
						if (player->getMoney() < acc->getPrice(buy))
						{
							printf("���� �����մϴ�.\n");
							Sleep(1000);
							continue;
						}
						else
						{
							if (acc->selling(buy))
							{
								inven->addItems(acc->getInfo(buy));
								player->setMoney(player->getMoney() - acc->getPrice(buy));
							}
						}
					}
					Sleep(1000);
				}
			}
			else if (key == 52)
			{
				while (1)
				{
					portion->showItems();
					buying();
					cin >> buy;
					if (buy == 0)
						break;
					else if (buy > 3)
					{
						printf("�߸��� �Է��Դϴ�.\n");
						Sleep(1000);
						continue;
					}
					else
					{
						if (player->getMoney() < acc->getPrice(buy))
						{
							printf("���� �����մϴ�.\n");
							Sleep(1000);
							continue;
						}
						else 
						{
							if (portion->selling(buy))
							{
								inven->addItems(portion->getInfo(buy));
								player->setMoney(player->getMoney() - portion->getPrice(buy));
							}
						}
					}
					Sleep(1000);
				}
			}
		}
		else if (key == 50)
		{
			while (1)
			{
				system("cls");
				inven->showInven();
				sell();
				cin >> sellNum;
				if (sellNum == 0)
					break;
				else if (sellNum > inven->getInvenSize())
				{
					printf("�߸��� �Է��Դϴ�.\n");
					Sleep(1000);
					continue;
				}
				else
				{
					itemInfo it = inven->sellItems(sellNum);
					Sleep(1000);
					switch (it.nType)
					{
					case WEAPON:
						weapon->restock(it.nNum);
						player->setMoney(player->getMoney() + it.nPrice);
						break;
					case SHIELD:
						shield->restock(it.nNum);
						player->setMoney(player->getMoney() + it.nPrice);
						break;
					case ACC:
						acc->restock(it.nNum);
						player->setMoney(player->getMoney() + it.nPrice);
						break;
					case PORTION:
						portion->restock(it.nNum);
						player->setMoney(player->getMoney() + it.nPrice);
						break;
					}
				}
				
			}
		}
		else if (key == 51)
		{
			while (1)
			{
				player->showStats();
				usedItem();
				inven->showInven();
				selectUse();
				cin >> use;
				if (use == 0)
					break;
				else if (use > inven->getInvenSize())
				{
					printf("�߸��� �Է��Դϴ�.\n");
					Sleep(1000);
					continue;
				}
				else
				{
					itemInfo info = inven->sellItems(use);
					Sleep(1000);
					switch (info.nType)
					{
					case WEAPON:
						if (saved[0].nNum != 0)
							inven->addItems(saved[0]);

						player->setUsedWeapon(info.sName);
						saved[0] = info;					
						break;
					case SHIELD:
						if (saved[1].nNum != 0)
							inven->addItems(saved[1]);
							
						player->setUsedShield(info.sName);
						saved[1] = info;
						break;
					case ACC:
						if (saved[2].nNum != 0)
							inven->addItems(saved[2]);
						
						player->setUsedAcc(info.sName);
						saved[2] = info;
						break;
					case PORTION:
						if (saved[3].nNum != 0)
							inven->addItems(saved[3]);
						
						player->setUsedPortion(info.sName);
						saved[3] = info;
						break;
					}
				}
			}
		}
 
		system("cls");
	}
}
