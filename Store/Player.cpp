#include "Player.h"

Player::Player()
{
	_name = "���Ͼ�ī������ ���";
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
	printf("          �÷��̾� ����        \n");
	printf("-----------------------------------\n");
	printf(" �÷��̾� �̸� : %s\n", _name);
	printf(" ü�� : %d\n",_hp);
	printf(" ���� : %d\n", _mp);
	printf(" ���ݷ� : %d\n", _att);
	printf(" ���� : %d \n", _def);
	printf(" ���� �Ӵ� : %d\n", _money);
	printf("-----------------------------------\n");
}
