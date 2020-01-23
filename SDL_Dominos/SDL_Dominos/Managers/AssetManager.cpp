//
//  AssetManager.cpp
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-15.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "AssetManager.h"

namespace SDLFramework
{

AssetManager * AssetManager::sInstance = nullptr;

AssetManager * AssetManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new AssetManager();
	}
	
	return sInstance;
}

void AssetManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

AssetManager::AssetManager()
{
	
}

AssetManager::~AssetManager()
{
	for (auto tex : mTextures)
	{
		if (tex.second != nullptr)
		{
			SDL_DestroyTexture(tex.second);
		}
	}
	mTextures.clear();
}

SDL_Texture * AssetManager::GetTexture(std::string filename, bool managed)
{
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	
	if (mTextures[fullPath] == nullptr)
	{
		mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
	}
	
	if (mTextures[fullPath] != nullptr && managed)
	{
		mTextureRefCount[mTextures[fullPath]] ++;
	}
	
	return mTextures[fullPath];
}

void AssetManager::DestroyTexture(SDL_Texture *texture)
{
	if (mTextureRefCount.find(texture) != mTextureRefCount.end())
	{
		mTextureRefCount[texture]--;
		if (mTextureRefCount[texture] == 0)
		{
			for (auto elem : mTextures)
			{
				if (elem.second == texture)
				{
					SDL_DestroyTexture(elem.second);
					mTextures.erase(elem.first);
					return;
				}
			}
			for (auto elem : mTexts)
			{
				if (elem.second == texture)
				{
					SDL_DestroyTexture(elem.second);
					mTexts.erase(elem.first);
					return;
				}
			}
		}
	}
}

TTF_Font * AssetManager::GetFont(std::string filename, int size)
{
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	
	std::stringstream ss;
	ss << size;
	std::string key = fullPath + ss.str();
	
	if (mFonts[key] == nullptr)
	{
		mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
		if (mFonts[key] == nullptr)
		{
			std::cerr << "Unable to load font " << filename << "! TTF Error: " << TTF_GetError() << std::endl;
		}
	}
	return mFonts[key];
}

SDL_Texture * AssetManager::GetText(std::string text, std::string fontPath, int size, SDL_Color color, bool managed)
{
	std::stringstream ss;
	ss << size << (int)color.r << (int)color.g << (int)color.b;
	std::string key = text + fontPath + ss.str();
	
	if (mTexts[key] == nullptr)
	{
		TTF_Font * font = GetFont(fontPath, size);
		mTexts[key] = Graphics::Instance()->CreateTextTexture(text, font, color);
	}
	
	if (mTexts[key] != nullptr && managed)
	{
		mTextureRefCount[mTexts[key]]++;
	}
	
	return mTexts[key];
}

Mix_Music * AssetManager::GetMusic(std::string filename, bool managed)
{
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	
	if (mMusic[fullPath] == nullptr)
	{
		mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
	}
	
	if (mMusic[fullPath] == nullptr)
	{
		std::cerr << "Unable to load music " << filename << "! Mix error: " << Mix_GetError() << std::endl;
	}
	else if (managed)
	{
		mMusicRefCount[mMusic[fullPath]]++;
	}
	
	return mMusic[fullPath];
}

Mix_Chunk * AssetManager::GetSFX(std::string filename, bool managed)
{
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	
	if (mSFX[fullPath] == nullptr)
	{
		mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
	}
	
	if (mSFX[fullPath] == nullptr)
	{
		std::cerr << "Unable to load SFX " << filename << "! Mix error: " << Mix_GetError() << std::endl;
	}
	else if (managed)
	{
		mSFXRefCount[mSFX[fullPath]]++;
	}
	
	return mSFX[fullPath];
}

void AssetManager::DestroyMusic(Mix_Music * music)
{
	for (auto elem : mMusic)
	{
		if (elem.second == music)
		{
			mMusicRefCount[elem.second]--;
			if (mMusicRefCount[elem.second] == 0)
			{
				Mix_FreeMusic(elem.second);
				mMusic.erase(elem.first);
			}
			return;
		}
	}
}

void AssetManager::DestroySFX(Mix_Chunk * sfx)
{
	for (auto elem : mSFX)
	{
		if (elem.second == sfx)
		{
			mSFXRefCount[elem.second]--;
			if (mSFXRefCount[elem.second] == 0)
			{
				Mix_FreeChunk(elem.second);
				mSFX.erase(elem.first);
			}
			return;
		}
	}
}

}
