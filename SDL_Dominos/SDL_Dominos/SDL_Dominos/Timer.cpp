//
//  Timer.cpp
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-14.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//
#include "Timer.h"

namespace SDLFramework {

	Timer * Timer::sInstance = nullptr;
	
	Timer * Timer::Instance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new Timer();
		}
		return sInstance;
	}

	void Timer::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}
	
	void Timer::Reset()
	{
		mStartTicks = SDL_GetTicks();
		mElapsedTicks = 0;
		mDeltaTime = 0.0f;
	}

	float Timer::DeltaTime()
	{
		return mDeltaTime;
	}

	void Timer::TimeScale(float ts)
	{
		mTimeScale = ts;
	}

	float Timer::TimeScale()
	{
		return mTimeScale;
	}
	
	void Timer::Update()
	{
		mElapsedTicks = SDL_GetTicks() - mStartTicks;
		mDeltaTime = mElapsedTicks * 0.001f; //Convert to Seconds
	}

	Timer::Timer()
	{
		Reset();
		mTimeScale = 1.0f;
	}

	Timer::~Timer()
	{
		
	}
}
