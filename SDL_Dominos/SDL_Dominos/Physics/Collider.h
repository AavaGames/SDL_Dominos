//
//  Collider.h
//  SDL_Dominos
//
//  Created by Philip Fertsman on 2020-01-24.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __COLLIDER_H
#define __COLLIDER_H
#include "Texture.h"

using namespace SDLFramework;

class Collider : public GameEntity {
public:
	enum class ColliderType { Box, Circle }; // type safety

protected:
	ColliderType mType;

	static const bool DEBUG_COLLIDERS = true;
	Texture * mDebugTexture;

	void SetDebugTexture(Texture * tex);

public:
	Collider(ColliderType type);
	virtual ~Collider();

	virtual Vector2 GetFurthestPoint() = 0;

	ColliderType GetType();

	virtual void Render() override;
};
#endif
