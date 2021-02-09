#pragma once
#include "SceneNode.h"
#include <memory>
#include "RenderItem.h"
class Entity : public SceneNode
{
public:
	std::unique_ptr<RenderItem> Ritem;
	void setVelocity(XMFLOAT3 velocity) { mVelocity = velocity; }
	void setVelocity(float x, float y) { mVelocity.x = x, mVelocity.y = y; }
	XMFLOAT3 getVelocity() { return mVelocity; }

private:
	XMFLOAT3 mVelocity;

};

