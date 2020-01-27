//
//  DominoEnemy.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-23.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __DOMINOENEMY_H
#define __DOMINOENEMY_H
#include "DominoUnit.h"

class DominoEnemy : public DominoUnit
{
public:
	DominoEnemy(UnitSide side);
	~DominoEnemy();

	void Input() override;
private:
	
};

#endif /* DominoEnemy_h */
