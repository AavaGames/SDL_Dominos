//
//  GameManager.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-14.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H

#include <SDL2/SDL.h>
#include "Timer.h"
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"

#include "DominoPlayer.h"
#include "DominoEnemy.h"

namespace SDLFramework
{

class GameManager
{
public:
	static GameManager * Instance();
	static void Release();
	
	void Run();
	void Update();
	void LateUpdate();
	void Render();
	
	GameManager();
	~GameManager();
	
private:
	static GameManager * sInstance;
	bool mQuit;
	Graphics * mGraphics;
	AssetManager * mAssetManager;
	InputManager * mInputManager;
	AudioManager * mAudioManager;
	
	SDL_Event mEvent;
	
	const int FRAME_RATE = 60;
	Timer * mTimer;
	
	enum ScreenType { Start, Playing, GameOver };
	ScreenType currentScreenType;
	
	Texture * mBackgroundTexture;
	Texture * mGameOverFont;
	Texture * mStartScreenPerCoinFont;
	Texture * mStartScreenWinGameFont;
	
	bool onePlayer;
	
	void BuildBoard(bool isOnePlayer);
	void BuildStartBoard();
	void ClearBoard();
	
	void AddPoint(bool leftSide);
	
	DominoPlayer * dominoPlayerOne;
	DominoPlayer * dominoPlayerTwo;
	DominoEnemy * dominoEnemyOne;
	DominoEnemy * dominoEnemyTwo;
	
	int leftPoints;
	int rightPoints;
};

}

#endif /* GameManager_h */
