#include "Shield.h"

Shield::Shield()
{
	shield[0] = { 2, 1, "���", 500, "�������� ����� ���� ��� ���. ���� �ް� �ʹٸ� ��õ", 25, 1};
	shield[1] = { 2, 2, "����", 1200, "�޴뼺 ���� ����. ��ư�� ������ ������", 45, 1 };
	shield[2] = { 2, 3, "��ź����", 1400, "��� ������ ����� ������ش�.", 40, 1 };
}

Shield::~Shield()
{
}

void Shield::showItems()
{
	system("cls");
	printf("========= �� ��� =========\n");
	printLine();
	for (int i = 0; i < 3; ++i)
	{
		printf("��ȣ: %d\n", shield[i].nNum);
		printf("�̸�: %s\n", shield[i].sName.c_str());
		printf("����: %d\n", shield[i].nPrice);
		printf("Ư¡: %s\n", shield[i].sChar.c_str());
		printf("��� ����: %d\n", shield[i].nStat);

		if (shield[i].nCount < 1)
			printf("ǰ��\n");
		else
			printf("����: %d\n", shield[i].nCount);

		printLine();
	}
}

int Shield::selling(int index)
{
	if (p->getMoney() < shield[index - 1].nPrice)
		printf("���� �����մϴ�.");

	if (shield[index - 1].nCount < 1)
		printf("ǰ���Դϴ�.");
	else
	{
		shield[index - 1].nCount -= 1;
		p->setMoney(p->getMoney() - shield[index - 1].nPrice);
		return 1;
	}
	return 0;
}
