//
//  CircleCollider.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-24.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __CIRCLECOLLIDER_H
#define __CIRCLECOLLIDER_H
#include "Collider.h"

class CircleCollider : public Collider {
private:
	float mRadius;

public:
	CircleCollider(float radius, bool broadPhase = false);
	~CircleCollider();

	Vector2 GetFurthestPoint() override;

	float GetRadius();
};


#endif
