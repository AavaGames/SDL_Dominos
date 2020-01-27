//
//  DominoUnit.cpp
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-23.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "DominoUnit.h"

DominoUnit::DominoUnit(UnitSide side)
{
	mInputManager = InputManager::Instance();
	mTimer = Timer::Instance();
	mStage = Stage::Instance();
	
	currentUnitState = Playing;
	currentUnitSide = side;
	
	turnTime = 1.0f;
	mCurrentSprite = nullptr;
	
	if (currentUnitSide == LeftSide)
	{
		currentTileType = Stage::LEFTUNIT;
		turnTimer = turnTime / 2;
		
		mUpSprite = new Texture("Art/Dominos_SpriteSheet.png", 360, 488, 16, 16, true);
		mDownSprite = new Texture("Art/Dominos_SpriteSheet.png", 324, 488, 16, 16, true);
		mRightSprite = new Texture("Art/Dominos_SpriteSheet.png", 378, 488, 16, 16, true);
		mLeftSprite = new Texture("Art/Dominos_SpriteSheet.png", 342, 488, 16, 16, true);
		
		mCurrentSprite = mRightSprite;
		
		currentDirection = Right;
		prevDirection = Right;

		mapPosition = Vector2(8, 13);
		//Set actual position
		MoveToMapCoord(mapPosition);
		CollisionCheck();
	}
	else
	{
		currentTileType = Stage::RIGHTUNIT;
		turnTimer = 0.0f;
		
		mUpSprite = new Texture("Art/Dominos_SpriteSheet.png", 360, 506, 16, 16, true);
		mDownSprite = new Texture("Art/Dominos_SpriteSheet.png", 324, 506, 16, 16, true);
		mRightSprite = new Texture("Art/Dominos_SpriteSheet.png", 378, 506, 16, 16, true);
		mLeftSprite = new Texture("Art/Dominos_SpriteSheet.png", 342, 506, 16, 16, true);
		
		mCurrentSprite = mLeftSprite;
		
		currentDirection = Left;
		prevDirection = Left;
		
		mapPosition = Vector2(23, 12);
		//Set actual position
		MoveToMapCoord(mapPosition);
		CollisionCheck();
	}
}

DominoUnit::~DominoUnit()
{
	mCurrentSprite = nullptr;
	
	delete mUpSprite;
	mUpSprite = nullptr;
	
	delete mDownSprite;
	mDownSprite = nullptr;
	
	delete mRightSprite;
	mRightSprite = nullptr;
	
	delete mLeftSprite;
	mLeftSprite = nullptr;
}

void DominoUnit::Update()
{
	if (currentUnitState == UnitState::Playing)
	{
		Input();
		if (Turn())
		{
			PlaceDomino();
			Movement();
		}
	}
	else if (currentUnitState == UnitState::Lose)
	{
		FallDominos();
		//Restart
	}
	//else do nothing;
}

void DominoUnit::Render()
{
		for (auto dom : dominoList)
	{
		dom->Render();
	}
	
	mCurrentSprite->Render();
}

bool DominoUnit::Turn()
{
	turnTimer += mTimer->DeltaTime();
	if (turnTimer >= turnTime)
	{
		turnTimer = 0.0f;
		
		turnTime *= 0.95;
		if (turnTime <= minTurnTime)
		{
			turnTime = minTurnTime;
		}
		
		return true;
	}
	else return false;
}

void DominoUnit::Movement()
{
	if (currentDirection == Up)
	{
		mCurrentSprite = mUpSprite;
		mapPosition.y--;
	}
	else if (currentDirection == Down)
	{
		mCurrentSprite = mDownSprite;
		mapPosition.y++;
	}
	else if (currentDirection == Right)
	{
		mCurrentSprite = mRightSprite;
		mapPosition.x++;
	}
	else if (currentDirection == Left)
	{
		mCurrentSprite = mLeftSprite;
		mapPosition.x--;
	}
	
	prevDirection = currentDirection;
	MoveToMapCoord(mapPosition);
	CollisionCheck();
}

void DominoUnit::MoveToMapCoord(Vector2 mapPos)
{
	mCurrentSprite->Position(mStage->MapToWorld(mapPos));
}

void DominoUnit::CollisionCheck()
{
	if (mStage->stageMap[(int)mapPosition.y][(int)mapPosition.x] == 0)
	{
		mStage->SetTile(currentTileType, mapPosition);
	}
	else currentUnitState = Lose;
}

void DominoUnit::PlaceDomino()
{
	//depending on direction and previous direction
	//place appropriate domino on previous position
	Domino * domino;
	if (currentUnitSide == LeftSide)
	{
		domino = new Domino(mStage->MapToWorld(mapPosition), true);
	}
	else
	{
		domino = new Domino(mStage->MapToWorld(mapPosition), false);
	}
	
	dominoList.push_back(domino);
}

void DominoUnit::FallDominos()
{
	//loop through domino list from last to first set to fallen
	//for (auto domino in dominoList)
		//domino.currentDominoState = Domino::DominoState::Fallen;
		//add delay
	//When done
}
