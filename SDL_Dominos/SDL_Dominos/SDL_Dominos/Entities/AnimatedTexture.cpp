//
//  AnimatedTexture.cpp
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-16.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//
#include "AnimatedTexture.h"

namespace SDLFramework {

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount,
    float animationSpeed, AnimDir animationDir, bool managed)
    : Texture(filename, x, y, w, h, managed)
{
	mTimer = Timer::Instance();
	mStartX = x;
	mStartY = y;
	
	mFrameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimerPerFrame = mAnimationSpeed / mFrameCount;
	mAnimationTimer = 0.0f;
	
	mWrapMode = Loop;
	mAnimationDirection = animationDir;
	mAnimationDone = false;
}

AnimatedTexture::~AnimatedTexture()
{
	
}

void AnimatedTexture::SetWrapMode(WrapMode mode)
{
	mWrapMode = mode;
}

void AnimatedTexture::ResetAnimation()
{
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
}

bool AnimatedTexture::IsAnimating()
{
	return !mAnimationDone;
}

void AnimatedTexture::Update()
{
	if (!mAnimationDone)
	{
		mAnimationTimer += mTimer->DeltaTime();
		if (mAnimationTimer >= mAnimationSpeed)
		{
			if (mWrapMode == Loop)
			{
				mAnimationTimer -= mAnimationSpeed;
			}
			else
			{
				mAnimationDone = true;
				//Go back to the last frame
				mAnimationTimer = mAnimationSpeed - mTimerPerFrame;
			}
		}
		
		if (mAnimationDirection == Horizontal)
		{
			mSourceRect.x = mStartX + (int)(mAnimationTimer / mTimerPerFrame) * mWidth;
		}
		else
		{
			mSourceRect.y = mStartY + (int)(mAnimationTimer / mTimerPerFrame) * mHeight;
		}
	}
}

}
