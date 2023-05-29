#include "Portion.h"

Portion::Portion()
{
	portion[0] = { 4, 1, "빨간물약", 300, "즉시 회복이 필요하다면 사용하세요", 150, 1 };
	portion[1] = { 4, 2, "파란물약", 150, "사용 후 일정 시간이 흐르면 회복", 100, 1 };
	portion[2] = { 4, 3, "노란물약", 450, "최대 HP를 늘려준다", 100, 1 };

}

Portion::~Portion()
{
}

void Portion::showItems()
{
	system("cls");
	printf("========= 포션 목록 =========\n");
	printLine();
	for (int i = 0; i < 3; ++i)
	{
		printf("번호: %d\n", portion[i].nNum);
		printf("이름: %s\n", portion[i].sName.c_str());
		printf("가격: %d\n", portion[i].nPrice);
		printf("특징: %s\n", portion[i].sChar.c_str());
		printf("회복력: % d\n", portion[i].nStat);

		if (portion[i].nCount < 1)
			printf("품절\n");
		else
			printf("개수: %d\n", portion[i].nCount);

		printLine();
	}
}

int Portion::selling(int index)
{
	if (p->getMoney() < portion[index - 1].nPrice)
		printf("돈이 부족합니다.");

	if (portion[index - 1].nCount < 1)
		printf("품절입니다.");
	else
	{
		portion[index - 1].nCount -= 1;
		p->setMoney(p->getMoney() - portion[index - 1].nPrice);
		return 1;
	}
	return 0;
}
