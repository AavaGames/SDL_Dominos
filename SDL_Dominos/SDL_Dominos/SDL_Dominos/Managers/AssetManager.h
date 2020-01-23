//
//  AssetManager.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-15.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __ASSETMANAGER_H
#define __ASSETMANAGER_H
#include "Graphics.h"
#include <map>
#include <sstream>
#include <SDL2_mixer/SDL_mixer.h>

namespace SDLFramework {

class AssetManager
{
public:
	static AssetManager * Instance();
	static void Release();
	
	SDL_Texture * GetTexture(std::string filename, bool managed = false);
	void DestroyTexture(SDL_Texture * texture);
	
	SDL_Texture * GetText(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = false);
	
	Mix_Music * GetMusic(std::string filename, bool managed = false);
	Mix_Chunk * GetSFX(std::string filename, bool managed = false);
	void DestroyMusic(Mix_Music * music);
	void DestroySFX(Mix_Chunk * sfx);
	
private:
	static AssetManager * sInstance;
	
	std::map<std::string, SDL_Texture *> mTextures;
	std::map<SDL_Texture *, unsigned> mTextureRefCount;
	std::map<std::string, TTF_Font *> mFonts;
	std::map<std::string, SDL_Texture *> mTexts;
	std::map<std::string, Mix_Music *> mMusic;
	std::map<std::string, Mix_Chunk *> mSFX;
	
	std::map<Mix_Music *, unsigned> mMusicRefCount;
	std::map<Mix_Chunk *, unsigned> mSFXRefCount;
	
	TTF_Font * GetFont(std::string filename, int size);
	
	AssetManager();
	~AssetManager();
};

}

#endif /* AssetManager_h */
