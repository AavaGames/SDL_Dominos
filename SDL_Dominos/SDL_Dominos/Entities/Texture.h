//
//  Texture.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-15.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __TEXTURE_H
#define __TEXTURE_H
#include "Graphics.h"
#include "GameEntity.h"
#include "AssetManager.h"

namespace SDLFramework {

class Texture : public GameEntity
{
public:
	Texture(std::string filename, bool managed = false);
	Texture(std::string filename, int x, int y, int w, int h, bool managed = false);
	Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = false);
	~Texture();
	
	Vector2 ScaledDimensions();
	
	void Render() override;
	
protected:
	SDL_Texture * mTex;
	Graphics * mGraphics;
	
	int mWidth;
	int mHeight;
	
	bool mClipped;
	SDL_Rect mSourceRect;
	SDL_Rect mDestinationRect;
};

}

#endif /* Texture_h */
