#include "PlayerJet.h"

PlayerJet::PlayerJet(XMFLOAT3 position, XMFLOAT3 scale)
{
	Position = position;
	Scale = scale;

}

void PlayerJet::Move(const GameTimer& gt)
{
	// W
	if (d3dUtil::IsKeyDown(0x57))
	{
		Position.z += 0.02f;
	}

	// A
	if (d3dUtil::IsKeyDown(0x41))
	{
		Position.x -= 0.02f;
	}

	// S
	if (d3dUtil::IsKeyDown(0x53))
	{
		Position.z -= 0.02f;
	}

	// D
	if (d3dUtil::IsKeyDown(0x44))
	{
		Position.x += 0.02f;
	}
}

void PlayerJet::Update(const GameTimer& gt)
{
	Move(gt);
}
