//
//  BoxCollider.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-24.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __BOXCOLLIDER_H
#define __BOXCOLLIDER_H
#include "Collider.h"

class BoxCollider : public Collider {
private:
	static const int MAX_VERTS = 4;

	GameEntity * mVerts[MAX_VERTS];

	void AddVert(int index, Vector2 pos);

public:
	BoxCollider(Vector2 size);
	~BoxCollider();

	Vector2 GetFurthestPoint() override;
};
#endif
