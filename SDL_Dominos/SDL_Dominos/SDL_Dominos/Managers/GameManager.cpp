//
//  GameManager.cpp
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-14.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//
#include "GameManager.h"

namespace SDLFramework {

GameManager * GameManager::sInstance = nullptr;

GameManager * GameManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new GameManager();
	}
	return sInstance;
}

void GameManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

GameManager::GameManager() : mQuit(false)
{
	mGraphics = Graphics::Instance();
	//If failed to create correctly shut down run
	if (!Graphics::Initialized())
	{
		mQuit = true;
	}
	
	mAssetManager = AssetManager::Instance();
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();
	mAudioManager = AudioManager::Instance();
	
	dominoPlayerOne = nullptr;
	dominoPlayerTwo = nullptr;
	dominoEnemyOne = nullptr;
	dominoEnemyTwo = nullptr;
	
	BuildStartBoard();
	currentScreenType = Start;
	onePlayer = true;
	
	mBackgroundTexture = new Texture("Art/Dominos_SpriteSheet.png", 0, 0, 512, 448, false);
	mBackgroundTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT*0.5f));
	
	int size = 16;
	mGameOverFont = new Texture("GAME OVER", "Fonts/emulogic.TTF", size, { 255, 255, 255 }, false);
	mGameOverFont->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, size/2));
	
	mStartScreenPerCoinFont = new Texture("1 PLAY PER COIN", "Fonts/emulogic.TTF", size, { 255, 255, 255 }, false);
	mStartScreenPerCoinFont->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.18);
	
	mStartScreenWinGameFont = new Texture("4 POINTS WINS GAME", "Fonts/emulogic.TTF", size, { 255, 255, 255 }, false);
	mStartScreenWinGameFont->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.90);
}

GameManager::~GameManager()
{
	delete mBackgroundTexture;
	mBackgroundTexture = nullptr;
	
	delete mGameOverFont;
	mGameOverFont = nullptr;
	
	delete mStartScreenPerCoinFont;
	mStartScreenPerCoinFont = nullptr;
	
	delete mStartScreenWinGameFont;
	mStartScreenWinGameFont = nullptr;
	
	ClearBoard();
	
	Timer::Release();
	mTimer = nullptr;
	
	AssetManager::Release();
	mAssetManager = nullptr;
	
	InputManager::Release();
	mInputManager = nullptr;
	
	AudioManager::Release();
	mAudioManager = nullptr;
	
	Graphics::Release();
	mGraphics = nullptr;
	
	SDL_Quit();
}

void GameManager::Run()
{
	while (!mQuit)
	{
		mTimer->Update();
		
		while (SDL_PollEvent(&mEvent)) {
			switch (mEvent.type)
			{
				case SDL_QUIT:
					mQuit = true;
					break;
			}
		}
		
		if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE)
		{
			Update();
			LateUpdate();
			Render();
			mTimer->Reset();
		}
	}
}

void GameManager::Update()
{
	mInputManager->Update();
	
	if (currentScreenType == Start)
	{
		dominoEnemyOne->Update();
		dominoEnemyTwo->Update();
		
		if (mInputManager->KeyDown(SDL_SCANCODE_1))
		{
			BuildBoard(true);
			currentScreenType = Playing;
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_2))
		{
			BuildBoard(false);
			currentScreenType = Playing;
		}
	}
	else if (currentScreenType == Playing)
	{
		if (onePlayer)
		{
			dominoPlayerOne->Update();
			dominoEnemyOne->Update();
		}
		else
		{
			dominoPlayerOne->Update();
			dominoPlayerTwo->Update();
		}
	}
	else if (currentScreenType == GameOver)
	{
		//AddPoint(bool leftSide)
		if (leftPoints == 4 || rightPoints == 4)
		{
			//wait a litte
			leftPoints = 0;
			rightPoints = 0;
			
			BuildStartBoard();
			currentScreenType = Start;
		}
		else
		{
			//Wait a little
			BuildBoard(onePlayer);
		}
	}
}

void GameManager::LateUpdate()
{
	mInputManager->UpdatePrevInput();
}

void GameManager::Render()
{
	mGraphics->ClearBackBuffer();
	
	mBackgroundTexture->Render();
	
	if (currentScreenType == Start)
	{
		mGameOverFont->Render();
		mStartScreenPerCoinFont->Render();
		mStartScreenWinGameFont->Render();
		
		dominoEnemyOne->Render();
		dominoEnemyTwo->Render();
	}
	else if (currentScreenType == Playing)
	{
		if (onePlayer)
		{
			dominoPlayerOne->Render();
			dominoEnemyOne->Render();
		}
		else
		{
			dominoPlayerOne->Render();
			dominoPlayerTwo->Render();
		}
	}
	else if (currentScreenType == GameOver)
	{
		mGameOverFont->Render();
		
		if (onePlayer)
		{
			dominoPlayerOne->Render();
			dominoEnemyOne->Render();
		}
		else
		{
			dominoPlayerOne->Render();
			dominoPlayerTwo->Render();
		}
	}
	
	mGraphics->Render();
}

void GameManager::BuildBoard(bool isOnePlayer)
{
	onePlayer = isOnePlayer;
	
	ClearBoard();
	
	if (onePlayer)
	{
		dominoPlayerOne = new DominoPlayer(DominoUnit::Left);
		dominoEnemyOne = new DominoEnemy(DominoUnit::Right);
	}
	else
	{
		dominoPlayerOne = new DominoPlayer(DominoUnit::Left);
		dominoPlayerTwo = new DominoPlayer(DominoUnit::Right);
	}
}

void GameManager::BuildStartBoard()
{
	ClearBoard();
	
	dominoEnemyOne = new DominoEnemy(DominoUnit::Left);
	dominoEnemyTwo = new DominoEnemy(DominoUnit::Right);
}

void GameManager::ClearBoard()
{
	delete dominoPlayerOne;
	dominoPlayerOne = nullptr;
	
	delete dominoPlayerTwo;
	dominoPlayerTwo = nullptr;
	
	delete dominoEnemyOne;
	dominoEnemyOne = nullptr;
	
	delete dominoEnemyTwo;
	dominoEnemyTwo = nullptr;
}

void GameManager::AddPoint(bool leftSide)
{
	if (leftSide)
	{
		leftPoints++;
	}
	else
	{
		rightPoints++;
	}
}

}
