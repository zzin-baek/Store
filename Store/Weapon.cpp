#include "Weapon.h"

Weapon::Weapon()
{
	weapon[0] = { 1, 1, "��������", 2000, "���Ÿ� ���ݹ���. ��带 ����ٸ� �ִ� 1000�� �������� ����.", 40, 1 };
	weapon[1] = { 1, 2, "��������" , 2300, "�������� ��� ��. ���� �ð� ��� �� ��¡�� �ʿ��ϴ�.", 50, 1 };
	weapon[2] = { 1, 3, "Ȱ", 1800, "���Ÿ� ����. ȭ���� ��� ������ �ֱ� ������ ���̵� ��", 25, 1 };
	weapon[3] = { 1, 4, "�⺻����", 1000, "�⺻ ���ݹ���. 15���� �⺻���� �� ��� �� �������� �ʿ��ϴ�.", 20, 1 };
	weapon[4] = { 1, 5, "��ź", 800, "��ô ����. ���� �̰� 5�� �� �����Ѵ�.", 0, 3 };
}

Weapon::~Weapon()
{
}

void Weapon::showItems()
{
	system("cls");
	printf("========= ���� ��� =========\n");
	printLine();
	for (int i = 0; i < 5; ++i)
	{
		printf("��ȣ: %d\n", weapon[i].nNum);
		printf("�̸�: %s\n", weapon[i].sName.c_str());
		printf("����: %d\n", weapon[i].nPrice);
		printf("Ư¡: %s\n", weapon[i].sChar.c_str());
		printf("��� ���ݷ�: %d\n", weapon[i].nStat);

		if (weapon[i].nCount < 1)
			printf("ǰ��\n");
		else
			printf("����: %d\n", weapon[i].nCount);

		printLine();
	}
	
}

int Weapon::selling(int index)
{
	if (p->getMoney() < weapon[index - 1].nPrice)
		printf("���� �����մϴ�.");

	if (weapon[index - 1].nCount < 1)
		printf("ǰ���Դϴ�.");
	else
	{
		weapon[index - 1].nCount -= 1;
		p->setMoney(p->getMoney() - weapon[index - 1].nPrice);
		return 1;
	}
	return 0;
}

