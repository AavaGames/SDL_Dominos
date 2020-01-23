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

class DominoUnit
{
public:
	enum UnitState { Waiting, Playing, Win, Lose };
	UnitState currentUnitState;
	
	enum UnitSide { Left, Right };
	UnitSide currentUnitSide;
	
	DominoUnit(UnitSide side);
	~DominoUnit();
	
	void Update();
	void Render();
private:
	std::vector<Domino> dominoList;
	
	Texture * mTexture;
	
	void Movement();
	void PlaceDomino();
	void FallDominos();
};

#endif /* DominoUnit_h */
