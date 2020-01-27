//
//  PhysEntity.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-24.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __PHYSENTITY_H
#define __PHYSENTITY_H
#include <vector>
#include "Collider.h"

class PhysEntity : public GameEntity {
protected:
	unsigned long mId;

	std::vector<Collider *> mColliders;

	Collider * mBroadPhaseCollider;

	void AddCollider(Collider * collider, Vector2 localPos = Vec2_Zero);

	virtual bool IgnoreCollisions();

public:
	PhysEntity();
	~PhysEntity();

	unsigned long GetId();

	bool CheckCollision(PhysEntity * other);

	virtual void Hit(PhysEntity * other) { }

	virtual void Render() override;
};
#endif
