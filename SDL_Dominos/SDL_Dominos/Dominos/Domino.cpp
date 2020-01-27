//
//  Domino.cpp
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-23.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "Domino.h"

Domino::Domino(Vector2 pos, bool leftSide)
{
	currentDominoState = Standing;
	
	if (leftSide)
	{
		mCurrentTexture = new Texture("Art/Dominos_SpriteSheet.png", 72, 488, 16, 16, true);
	}
	else
	{
		mCurrentTexture = new Texture("Art/Dominos_SpriteSheet.png", 72, 506, 16, 16, true);
	}
	
	mCurrentTexture->Position(pos);
}

Domino::~Domino()
{
	delete mCurrentTexture;
	mCurrentTexture = nullptr;
}

void Domino::Update()
{
	if (currentDominoState == Fallen)
	{
		//Fall
	}
}

void Domino::Render()
{
	mCurrentTexture->Render();
}
