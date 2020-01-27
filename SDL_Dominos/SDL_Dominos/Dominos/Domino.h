//
//  Domino.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-23.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __DOMINO_H
#define __DOMINO_H
#include "Texture.h"

using namespace SDLFramework;

class Domino //: public Texture
{
public:
	enum DominoState { Standing, Fallen };
	DominoState currentDominoState;
	
	Domino(Vector2 pos, bool leftSide);
	~Domino();
	
	void Update();
	void Render();
private:
	/*
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	Texture * m
	*/
	Texture * mCurrentTexture;
};

#endif /* Domino_h */
