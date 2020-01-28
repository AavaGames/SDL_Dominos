//
//  Graphics.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-13.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __GRAPHICS_H
#define __GRAPHICS_H
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

namespace SDLFramework {

class Graphics
{
public:
	static const short SCREEN_WIDTH = 512;
	static const short SCREEN_HEIGHT = 448;
	static const short WINDOWSCALE = 2;
	
	static Graphics * Instance();
	static void Release ();
	static bool Initialized();
	
	SDL_Texture * LoadTexture(std::string path);
	SDL_Texture * CreateTextTexture(std::string text, TTF_Font * font, SDL_Color color);
	
	void DrawTexture(SDL_Texture * tex, SDL_Rect * srcRect = nullptr, SDL_Rect * dstRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	void ClearBackBuffer();
	void Render();
	
private:
	static Graphics * sInstance;
	static bool sInitialized;
	SDL_Window * mWindow = nullptr;
	SDL_Renderer * mRenderer = nullptr;
	
	Graphics();
	~Graphics();
	
	bool Init();
};

}
#endif /* Graphics_h */
