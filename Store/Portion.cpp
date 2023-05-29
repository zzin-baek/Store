#include "Portion.h"

Portion::Portion()
{
	portion[0] = { 4, 1, "��������", 300, "��� ȸ���� �ʿ��ϴٸ� ����ϼ���", 150, 1 };
	portion[1] = { 4, 2, "�Ķ�����", 150, "��� �� ���� �ð��� �帣�� ȸ��", 100, 1 };
	portion[2] = { 4, 3, "�������", 450, "�ִ� HP�� �÷��ش�", 100, 1 };

}

Portion::~Portion()
{
}

void Portion::showItems()
{
	system("cls");
	printf("========= ���� ��� =========\n");
	printLine();
	for (int i = 0; i < 3; ++i)
	{
		printf("��ȣ: %d\n", portion[i].nNum);
		printf("�̸�: %s\n", portion[i].sName.c_str());
		printf("����: %d\n", portion[i].nPrice);
		printf("Ư¡: %s\n", portion[i].sChar.c_str());
		printf("ȸ����: % d\n", portion[i].nStat);

		if (portion[i].nCount < 1)
			printf("ǰ��\n");
		else
			printf("����: %d\n", portion[i].nCount);

		printLine();
	}
}

int Portion::selling(int index)
{
	if (p->getMoney() < portion[index - 1].nPrice)
		printf("���� �����մϴ�.");

	if (portion[index - 1].nCount < 1)
		printf("ǰ���Դϴ�.");
	else
	{
		portion[index - 1].nCount -= 1;
		p->setMoney(p->getMoney() - portion[index - 1].nPrice);
		return 1;
	}
	return 0;
}
