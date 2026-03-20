#include "PlayerLaser.h"

#include "ConsoleRenderer.h"
#include "PlayField.h"

#include <string>

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerLaser");
	sprite = RS_PlayerLaser;
}

PlayerLaser::~PlayerLaser()
{
	delete[] m_objType;
}

void PlayerLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y -= 1.f;
	if (pos.y < 0)
	{
		deleted = true;
	}

	auto currentGameObjects = world.GameObjects();
	for (auto& it : currentGameObjects)
	{
		if (pos.IntCmp(it->pos) && strcmp(it->m_objType, "AlienShip") == 0)
		{
			deleted = true;
			auto shouldDie = it->DecreaseHealth();
			if (shouldDie)
				world.RemoveObject(it);
		}
	}

	if (deleted)
	{
		world.DespawnLaser(this);
	}
}