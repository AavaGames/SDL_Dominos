//
//  Stage.cpp
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-24.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "Stage.h"

Stage * Stage::sInstance = nullptr;

Stage * Stage::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new Stage();
	}
	
	return sInstance;
}

void Stage::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

Stage::Stage()
{
	InitializeStage();
}

Stage::~Stage()
{
	
}

void Stage::InitializeStage()
{
	for (int i = 0; i < COLUMN_SIZE; i++)
	{
		for (int j = 0; j < ROW_SIZE; j++)
		{
			if (i == 0 || i == COLUMN_SIZE - 1 || j == 0 || j == ROW_SIZE - 1)
			{
				stageMap[i][j] = WALL;
			}
			else
			{
				stageMap[i][j] = EMPTY;
			}
		}
	}
}

Vector2 Stage::MapToWorld(int row, int column)
{
	return Vector2(row * TILE_SIZE, column * TILE_SIZE) + MAP_OFFSET;
}

Vector2 Stage::MapToWorld(Vector2 vec)
{
	return Vector2(vec.x * TILE_SIZE, vec.y * TILE_SIZE) + MAP_OFFSET;
}

Vector2 Stage::WorldToMap(int x, int y)
{
	return Vector2(x / TILE_SIZE, y / TILE_SIZE) - MAP_OFFSET;
}

Vector2 Stage::WorldToMap(Vector2 vec)
{
	vec += MAP_OFFSET;
	return Vector2(vec.x / TILE_SIZE, vec.y / TILE_SIZE) - MAP_OFFSET;
}

void Stage::SetTile(TileType tile, int row, int column)
{
	stageMap[column][row] = tile;
}

void Stage::SetTile(TileType tile, Vector2 vec)
{
	stageMap[(int)vec.y][(int)vec.x] = tile;
}

void Stage::PrintStage()
{
	for (int i = 0; i < COLUMN_SIZE; i++)
	{
		for (int j = 0; j < ROW_SIZE; j++)
		{
			std::cout << stageMap[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
