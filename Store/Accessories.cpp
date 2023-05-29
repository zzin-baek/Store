#include "Accessories.h"

Accessories::Accessories()
{
	acc[0] = { 3, 1, "����", 800, "��ġ ��ô ����� �޷��ִ� Ư�� ���� ����. ���� ���� ���� ������ �� �ִ�.", 20, 1 };
	acc[1] = { 3, 2, "�����", 400, "��� �� ���� �Ͱ� ���� �ٸ��� �ʴ�. Ư���� ����� ��������..?", 15, 1 };
	acc[2] = { 3, 3, "Ű��", 300, "���⿡ �� �� �ִ� Ű��. ������ ����� �����Ѵ�.", 10, 3 };
}

Accessories::~Accessories()
{
}

void Accessories::showItems()
{
	system("cls");
	printf("========= �Ǽ����� ��� =========\n");
	printLine();
	for (int i = 0; i < 3; ++i)
	{
		printf("��ȣ: %d\n", acc[i].nNum);
		printf("�̸�: %s\n", acc[i].sName.c_str());
		printf("����: %d\n", acc[i].nPrice);
		printf("Ư¡: %s\n", acc[i].sChar.c_str());
		printf("��� ����: %d\n", acc[i].nStat);

		if (acc[i].nCount < 1)
			printf("ǰ��\n");
		else
			printf("����: %d\n", acc[i].nCount);

		printLine();
	}
}

int Accessories::selling(int index)
{
	if (acc[index - 1].nCount < 1)
		printf("ǰ���Դϴ�.");
	else
	{
		acc[index - 1].nCount -= 1;
		return 1;
	}
	return 0;
}
