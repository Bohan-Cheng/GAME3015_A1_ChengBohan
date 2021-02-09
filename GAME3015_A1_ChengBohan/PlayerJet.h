#pragma once
#include "Entity.h"
#include "Common/d3dUtil.h"
#include "Common/GameTimer.h"
class PlayerJet : public Entity
{
public:
	PlayerJet() {};
	PlayerJet(XMFLOAT3 position, XMFLOAT3 scale);
	void Move(const GameTimer& gt);

	void Update(const GameTimer& gt);
};

