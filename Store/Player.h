#pragma once
#include "header.h"

class Player
{
private:
	const char* _name;
	int _hp;
	int _mp;
	int _att;
	int _def;
	int _money;

	std::string usedWeapon;
	std::string usedShield;
	std::string usedAcc;
	std::string usedPortion;

public:
	Player();
	~Player();

	void setHP(int hp) { _hp = hp; }
	int getHP() { return _hp; }

	void setMP(int mp) { _mp = mp; }
	int getMP() { return _mp; }

	void setAtt(int att) { _att = att; }
	int getAtt() { return _att; }

	void setDef(int def) { _def = def; }
	int getDef() { return _def; }

	void setMoney(int money) { _money = money; }
	int getMoney() { return _money; }

	void setUsedWeapon(std::string name) { usedWeapon = name; }
	std::string getUsedWeapon() { return usedWeapon; }

	void setUsedShield(std::string name) { usedShield = name; }
	std::string getUsedShield() { return usedShield; }

	void setUsedAcc(std::string name) { usedAcc = name; }
	std::string  getUsedAcc() { return usedAcc; }

	void setUsedPortion(std::string name) { usedPortion = name; }
	std::string getUsedPortion() { return usedPortion; }

	void showStats();

};

