#include "Player.h"

Player::Player()
{
	_name = "경일아카데미의 용사";
	_hp = 300;
	_mp = 200;
	_att = 150;
	_def = 150;
	_money = 10000;
}

Player::~Player()
{
}

void Player::showStats()
{
	system("cls");
	printf("-----------------------------------\n");
	printf("          플레이어 스탯        \n");
	printf("-----------------------------------\n");
	printf(" 플레이어 이름 : %s\n", _name);
	printf(" 체력 : %d\n",_hp);
	printf(" 마나 : %d\n", _mp);
	printf(" 공격력 : %d\n", _att);
	printf(" 방어력 : %d \n", _def);
	printf(" 보유 머니 : %d\n", _money);
	printf("-----------------------------------\n");
}
