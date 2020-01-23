//
//  AudioManager.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-17.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __AUDIOMANAGER_H
#define __AUDIOMANAGER_H
#include "AssetManager.h"
//#include "GameManager.h"

namespace SDLFramework {

class AudioManager
{
public:
	static AudioManager * Instance();
	static void Release();
	
	//void PlayMusic(std::string filename, int loops = -1);
	Mix_Music * PlayMusic(std::string filename, int loops, bool returnPointer = false, bool managed = false);
	void PlayMusic(Mix_Music * music, int loops = -1);
	void PauseMusic();
	void ResumeMusic();
	void StopMusic(); //Test
	
	//void PlaySFX(std::string filename, int loops = 0, int channel = -1);
	Mix_Chunk * PlaySFX(std::string filename, int loops, int channel, bool returnPointer = false, bool managed = false);
	void PlaySFX(Mix_Chunk * sfx, int loops = 0, int channel = -1);
	void StopSFX(int channel); //Would have to know channel of SFX
	
private:
	static AudioManager * sInstance;
	AssetManager * mAssetManager;
	
	AudioManager();
	~AudioManager();
};

}

#endif /* AudioManager_h */
