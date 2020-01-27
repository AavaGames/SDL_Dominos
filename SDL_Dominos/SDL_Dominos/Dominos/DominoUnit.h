//
//  DominoUnit.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-23.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __DOMINOUNIT_H
#define __DOMINOUNIT_H
#include "Domino.h"
#include "Texture.h"
#include <vector>
#include "InputManager.h"
#include "Stage.h"
#include "Timer.h"
#include <iostream>

class DominoUnit
{
public:
	enum UnitState { Waiting, Playing, Win, Lose };
	UnitState currentUnitState;
	
	enum UnitSide { LeftSide, RightSide };
	UnitSide currentUnitSide;
	Stage::TileType currentTileType;
	
	enum Direction { Up, Right, Down, Left };
	Direction currentDirection;
	Direction prevDirection;
	
	DominoUnit(UnitSide side);
	~DominoUnit();
	
	void Update();
	void Render();

	float turnTimer;
	float turnTime;
	const float minTurnTime = 0.2f;
	
	virtual void Input() {};
	bool Turn();
	void Movement();
	void PlaceDomino();
	void FallDominos();
protected:
	Timer * mTimer;
	InputManager * mInputManager;
	Stage * mStage;
	
	std::vector<Domino *> dominoList;
	
	Texture * mUpSprite;
	Texture * mDownSprite;
	Texture * mRightSprite;
	Texture * mLeftSprite;
	
	Texture * mCurrentSprite;

	Vector2 mapPosition = Vec2_Zero;
	
	void MoveToMapCoord(Vector2 mapPos);
	
	void CollisionCheck();
};

#endif /* DominoUnit_h */
