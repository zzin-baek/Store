#include "Weapon.h"

Weapon::Weapon()
{
	weapon[0] = { 1, 1, "라이플총", 2000, "원거리 저격무기. 헤드를 맞춘다면 최대 1000의 데미지가 들어간다.", 40, 1 };
	weapon[1] = { 1, 2, "레이저건" , 2300, "레이저를 쏘는 총. 일정 시간 사용 후 차징이 필요하다.", 50, 1 };
	weapon[2] = { 1, 3, "활", 1800, "원거리 무기. 화살을 쏘면 낙차가 있기 때문에 난이도 상", 25, 1 };
	weapon[3] = { 1, 4, "기본권총", 1000, "기본 공격무기. 15발이 기본으로 다 사용 시 재장전이 필요하다.", 20, 1 };
	weapon[4] = { 1, 5, "폭탄", 800, "투척 무기. 핀을 뽑고 5초 뒤 폭발한다.", 0, 3 };
}

Weapon::~Weapon()
{
}

void Weapon::showItems()
{
	system("cls");
	printf("========= 무기 목록 =========\n");
	printLine();
	for (int i = 0; i < 5; ++i)
	{
		printf("번호: %d\n", weapon[i].nNum);
		printf("이름: %s\n", weapon[i].sName.c_str());
		printf("가격: %d\n", weapon[i].nPrice);
		printf("특징: %s\n", weapon[i].sChar.c_str());
		printf("상승 공격력: %d\n", weapon[i].nStat);

		if (weapon[i].nCount < 1)
			printf("품절\n");
		else
			printf("개수: %d\n", weapon[i].nCount);

		printLine();
	}
	
}

int Weapon::selling(int index)
{
	if (p->getMoney() < weapon[index - 1].nPrice)
		printf("돈이 부족합니다.");

	if (weapon[index - 1].nCount < 1)
		printf("품절입니다.");
	else
	{
		weapon[index - 1].nCount -= 1;
		p->setMoney(p->getMoney() - weapon[index - 1].nPrice);
		return 1;
	}
	return 0;
}

