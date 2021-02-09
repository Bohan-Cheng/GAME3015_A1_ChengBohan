#pragma once
#include <string>
#include <map>
#include <vector>
#include "PlayerJet.h"
#include "Enemy.h"
class World
{
public:
	std::vector<Entity*> AllEntities;

	std::map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
	std::map<std::string, std::unique_ptr<Material>> mMaterials;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;
	// Render items divided by PSO.
	std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	PlayerJet* jet = new PlayerJet();
	Enemy* enemy = new Enemy();

	void buildWorld();

	void Update(const GameTimer& gt);
};

