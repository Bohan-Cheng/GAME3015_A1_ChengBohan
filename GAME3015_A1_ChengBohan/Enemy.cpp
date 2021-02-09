#include "Enemy.h"

Enemy::Enemy(XMFLOAT3 position, XMFLOAT3 scale)
{
	Position = position;
	Scale = scale;
}

void Enemy::Move(const GameTimer& gt)
{
	if (right)
	{
		Position.x += 0.02f;
	}
	else
	{
		Position.x -= 0.02f;
	}
	if (Position.x >= 50.0f)
	{
		right = false;
	}
	if (Position.x <= -50.0f)
	{
		right = true;
	}

}

void Enemy::Update(const GameTimer& gt)
{
	Move(gt);
}
