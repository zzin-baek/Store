#include "Accessories.h"

Accessories::Accessories()
{
	acc[0] = { 3, 1, "팔찌", 800, "위치 추척 기능이 달려있는 특수 제작 팔찌. 범위 내의 적을 감지할 수 있다.", 20, 1 };
	acc[1] = { 3, 2, "헤어밴드", 400, "운동할 때 쓰는 것과 별반 다르지 않다. 특수한 기능이 있을지도..?", 15, 1 };
	acc[2] = { 3, 3, "키링", 300, "무기에 달 수 있는 키링. 갖가지 모양이 존재한다.", 10, 3 };
}

Accessories::~Accessories()
{
}

void Accessories::showItems()
{
	system("cls");
	printf("========= 악세서리 목록 =========\n");
	printLine();
	for (int i = 0; i < 3; ++i)
	{
		printf("번호: %d\n", acc[i].nNum);
		printf("이름: %s\n", acc[i].sName.c_str());
		printf("가격: %d\n", acc[i].nPrice);
		printf("특징: %s\n", acc[i].sChar.c_str());
		printf("상승 마나: %d\n", acc[i].nStat);

		if (acc[i].nCount < 1)
			printf("품절\n");
		else
			printf("개수: %d\n", acc[i].nCount);

		printLine();
	}
}

int Accessories::selling(int index)
{
	if (acc[index - 1].nCount < 1)
		printf("품절입니다.");
	else
	{
		acc[index - 1].nCount -= 1;
		return 1;
	}
	return 0;
}
