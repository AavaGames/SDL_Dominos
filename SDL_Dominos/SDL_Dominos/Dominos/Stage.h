//
//  Stage.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-24.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef Stage_h
#define Stage_h
#include "MathHelper.h"

#include <iostream>

using namespace SDLFramework;

class Stage {
public:
	static Stage * Instance();
	static void Release ();
	
	static const int TILE_SIZE = 16;
	static const int COLUMN_SIZE = 26;
	static const int ROW_SIZE = 32;
	const Vector2 MAP_OFFSET = Vector2((TILE_SIZE / 2), (TILE_SIZE / 2) + (TILE_SIZE * 2));
	enum TileType { EMPTY = 0, LEFTUNIT = 1, RIGHTUNIT = 2, WALL = 5 };
	
	int stageMap [COLUMN_SIZE][ROW_SIZE] = {};
	
	void PrintStage();
	Vector2 MapToWorld(int row, int column);
	Vector2 MapToWorld(Vector2 vec);
	Vector2 WorldToMap(int x, int y);
	Vector2 WorldToMap(Vector2 vec);
	void InitializeStage();
	void SetTile(TileType tile, int row, int column);
	void SetTile(TileType tile, Vector2 vec);
	
	Stage();
	~Stage();
	
	//map starts at 0,0 needs an offset of TILE_SIZE / 2 for x + y then go down 
	
private:
	static Stage * sInstance;
	
};

#endif /* Stage_h */
