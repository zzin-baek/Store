#include "Shield.h"

Shield::Shield()
{
	shield[0] = { 2, 1, "헬멧", 500, "형광색의 상당히 눈에 띄는 헬멧. 관심 받고 싶다면 추천", 25, 1};
	shield[1] = { 2, 2, "방패", 1200, "휴대성 좋은 방패. 버튼을 누르면 펴진다", 45, 1 };
	shield[2] = { 2, 3, "방탄조끼", 1400, "어느 정도의 충격을 흡수해준다.", 40, 1 };
}

Shield::~Shield()
{
}

void Shield::showItems()
{
	system("cls");
	printf("========= 방어구 목록 =========\n");
	printLine();
	for (int i = 0; i < 3; ++i)
	{
		printf("번호: %d\n", shield[i].nNum);
		printf("이름: %s\n", shield[i].sName.c_str());
		printf("가격: %d\n", shield[i].nPrice);
		printf("특징: %s\n", shield[i].sChar.c_str());
		printf("상승 방어력: %d\n", shield[i].nStat);

		if (shield[i].nCount < 1)
			printf("품절\n");
		else
			printf("개수: %d\n", shield[i].nCount);

		printLine();
	}
}

int Shield::selling(int index)
{
	if (p->getMoney() < shield[index - 1].nPrice)
		printf("돈이 부족합니다.");

	if (shield[index - 1].nCount < 1)
		printf("품절입니다.");
	else
	{
		shield[index - 1].nCount -= 1;
		p->setMoney(p->getMoney() - shield[index - 1].nPrice);
		return 1;
	}
	return 0;
}
