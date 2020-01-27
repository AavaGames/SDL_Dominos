//
//  DominoPlayer.cpp
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-23.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "DominoPlayer.h"

DominoPlayer::DominoPlayer(UnitSide side) : DominoUnit(side)
{
	std::cerr << "Player Created" << std::endl;
}

DominoPlayer::~DominoPlayer()
{
	
}

void DominoPlayer::Input()
{
	if (currentUnitSide == LeftSide)
	{
		if (mInputManager->KeyDown(SDL_SCANCODE_W) && prevDirection != Down)
		{
			currentDirection = Up;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_S) && prevDirection != Up)
		{
			currentDirection = Down;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_D) && prevDirection != Left)
		{
			currentDirection = Right;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_A) && prevDirection != Right)
		{
			currentDirection = Left;
		}
		else
		{
			currentDirection = prevDirection;
		}
	}
	else
	{
		if (mInputManager->KeyDown(SDL_SCANCODE_O) && prevDirection != Down)
		{
			currentDirection = Up;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_L) && prevDirection != Up)
		{
			currentDirection = Down;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_SEMICOLON) && prevDirection != Left)
		{
			currentDirection = Right;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_K) && prevDirection != Right)
		{
			currentDirection = Left;
		}
		else
		{
			currentDirection = prevDirection;
		}
	}
}
