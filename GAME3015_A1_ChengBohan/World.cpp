#include "World.h"

void World::buildWorld()
{
	jet->Position = XMFLOAT3(0.0f, 0.1f, -30.0f);
	jet->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);
	enemy->Position = XMFLOAT3(0.0f, 0.1f, 20.0f);
	enemy->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	auto landRitem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&landRitem->World, XMMatrixScaling(2.5f, 1.0f, 2.5f) * XMMatrixTranslation(0.0f, 0.0f, 0.0f));
	landRitem->ObjCBIndex = 0;
	landRitem->Mat = mMaterials["LandMat"].get();
	landRitem->Geo = mGeometries["shapeGeo"].get();
	//landRitem->World = MathHelper::Identity4x4();
	landRitem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	landRitem->IndexCount = landRitem->Geo->DrawArgs["Grid"].IndexCount;
	landRitem->StartIndexLocation = landRitem->Geo->DrawArgs["Grid"].StartIndexLocation;
	landRitem->BaseVertexLocation = landRitem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Opaque].push_back(landRitem.get());
	mAllRitems.push_back(std::move(landRitem));

	jet->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&jet->Ritem->World, XMMatrixScaling(jet->Scale.x, jet->Scale.y, jet->Scale.z) * XMMatrixTranslation(jet->Position.x, jet->Position.y, jet->Position.z));
	jet->Ritem->ObjCBIndex = 1;
	jet->Ritem->Mat = mMaterials["JetMat"].get();
	jet->Ritem->Geo = mGeometries["shapeGeo"].get();
	jet->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	jet->Ritem->IndexCount = jet->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	jet->Ritem->StartIndexLocation = jet->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	jet->Ritem->BaseVertexLocation = jet->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(jet->Ritem.get());
	mAllRitems.push_back(std::move(jet->Ritem));
	AllEntities.push_back(jet);

	enemy->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy->Ritem->World, XMMatrixScaling(enemy->Scale.x, enemy->Scale.y, enemy->Scale.z) * XMMatrixTranslation(enemy->Position.x, enemy->Position.y, enemy->Position.z));
	enemy->Ritem->ObjCBIndex = 2;
	enemy->Ritem->Mat = mMaterials["Jet2Mat"].get();
	enemy->Ritem->Geo = mGeometries["shapeGeo"].get();
	enemy->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	enemy->Ritem->IndexCount = enemy->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	enemy->Ritem->StartIndexLocation = enemy->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	enemy->Ritem->BaseVertexLocation = enemy->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(enemy->Ritem.get());
	mAllRitems.push_back(std::move(enemy->Ritem));
	AllEntities.push_back(enemy);

}

void World::Update(const GameTimer& gt)
{

	jet->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&jet->Ritem->World, XMMatrixScaling(jet->Scale.x, jet->Scale.y, jet->Scale.z) * XMMatrixTranslation(jet->Position.x, jet->Position.y, jet->Position.z));
	jet->Ritem->ObjCBIndex = 1;
	mAllRitems.push_back(std::move(jet->Ritem));

	enemy->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy->Ritem->World, XMMatrixScaling(enemy->Scale.x, enemy->Scale.y, enemy->Scale.z) * XMMatrixTranslation(enemy->Position.x, enemy->Position.y, enemy->Position.z));
	enemy->Ritem->ObjCBIndex = 2;
	mAllRitems.push_back(std::move(enemy->Ritem));

	//XMStoreFloat4x4(&jet->Ritem->World, XMMatrixScaling(0,0,0) * XMMatrixTranslation(0,0,0));
	//mAllRitems.push_back(std::move(jet->Ritem));
	jet->Update(gt);
	enemy->Update(gt);
}
