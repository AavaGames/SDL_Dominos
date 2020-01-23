//
//  AudioManager.cpp
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-17.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "AudioManager.h"

namespace SDLFramework {

AudioManager * AudioManager::sInstance = nullptr;

AudioManager * AudioManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new AudioManager();
	}
	return sInstance;
}

void AudioManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

AudioManager::AudioManager()
{
	mAssetManager = AssetManager::Instance();
	
	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		std::cerr << "Unable to initialize SDL audio! SDL Error: " << SDL_GetError() << std::endl;
		return;
	}
	
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	{
		std::cerr << "Unable to initialize audio! Mix Error: " << Mix_GetError() << std::endl;
	}
}

AudioManager::~AudioManager()
{
	mAssetManager = nullptr;
	Mix_CloseAudio();
	Mix_Quit();
}

/* Textbook Code
void AudioManager::PlayMusic(std::string filename, int loops)
{
	Mix_PlayMusic(mAssetManager->GetMusic(filename), loops);
}
*/

//Combined Code
Mix_Music * AudioManager::PlayMusic(std::string filename, int loops, bool returnPointer, bool managed)
{
	Mix_Music * music = mAssetManager->GetMusic(filename, managed);
	Mix_PlayMusic(music, loops);
	if (returnPointer)
	{
		return music;
	}
	else
	{
		return nullptr;
	}
}

void AudioManager::PlayMusic(Mix_Music * music, int loops)
{
	Mix_PlayMusic(music, loops);
}

void AudioManager::PauseMusic()
{
	if (Mix_PlayingMusic() != 0)
	{
		Mix_PauseMusic();
	}
}

void AudioManager::ResumeMusic()
{
	if (Mix_PausedMusic() != 0)
	{
		Mix_ResumeMusic();
	}
}

void AudioManager::StopMusic()
{
	Mix_HaltMusic();
}

/* Textbook Code
void AudioManager::PlaySFX(std::string filename, int loops, int channel)
{
	Mix_PlayChannel(channel, mAssetManager->GetSFX(filename), loops);
}
*/

//Combined Code
Mix_Chunk * AudioManager::PlaySFX(std::string filename, int loops, int channel, bool returnPointer, bool managed)
{
	Mix_Chunk * sfx = mAssetManager->GetSFX(filename, managed);
	Mix_PlayChannel(channel, sfx, loops);
	if (returnPointer)
	{
		return sfx;
	}
	else
	{
		return nullptr;
	}
}

void AudioManager::PlaySFX(Mix_Chunk * sfx, int loops, int channel)
{
	Mix_PlayChannel(channel, sfx, loops);
}

void AudioManager::StopSFX(int channel)
{
	Mix_HaltChannel(channel);
}

}
