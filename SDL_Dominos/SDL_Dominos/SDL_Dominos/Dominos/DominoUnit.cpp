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
	currentUnitState = Waiting;
	currentUnitSide = side;
	
	if (currentUnitSide == Left)
	{
		mTexture = new Texture(Texture("Art/Dominos_SpriteSheet.png", 378, 488, 16, 16, true));
		mTexture->Position(50, 50);
	}
	else
	{
		mTexture = new Texture(Texture("Art/Dominos_SpriteSheet.png", 378, 506, 16, 16, true));
	}
}

DominoUnit::~DominoUnit()
{
	delete mTexture;
	mTexture = nullptr;
}

void DominoUnit::Update()
{
	//States
}

void DominoUnit::Render()
{
	mTexture->Render();
	//Domino List
	//for (auto domino in dominoList)
		//domino->Render();
}

void DominoUnit::Movement()
{
	if (currentUnitSide == Left)
	{
		
	}
	else
	{
		
	}
}

void DominoUnit::PlaceDomino()
{
	
}

void DominoUnit::FallDominos()
{
	
}
