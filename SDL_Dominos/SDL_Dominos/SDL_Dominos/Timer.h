//
//  Timer.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-14.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef Timer_h
#define Timer_h
#include <SDL2/SDL.h>

namespace SDLFramework
{

class Timer
{
public:
	static Timer * Instance();
	static void Release();
	void Reset();
	float DeltaTime();
	
	void TimeScale(float ts);
	float TimeScale();
	
	void Update();
	
private:
	static Timer * sInstance;
	
	unsigned int mStartTicks;
	unsigned int mElapsedTicks;
	float mDeltaTime;
	float mTimeScale;
	
	Timer();
	~Timer();
};

}

#endif /* Timer_h */
