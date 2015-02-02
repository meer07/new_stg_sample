#pragma once
#include "Enemy.h"

class MidEnemy02 : public Enemy {
public:
	static MidEnemy02* create(const float enemyParam[], const float shotParam[], std::string fileName);
	void Move();
	void Shot();
	void Destroy();

private:
	void MovePattern();
	float GetAngle();
	int shotCount;
	bool flag;
};
