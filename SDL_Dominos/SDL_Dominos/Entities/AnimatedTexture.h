//
//  AnimatedTexture.h
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-16.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#ifndef __ANIMATEDTEXTURE_H
#define __ANIMATEDTEXTURE_H
#include "Texture.h"
#include "Timer.h"

namespace SDLFramework {

class AnimatedTexture : public Texture
{
public:
	enum WrapMode { Once = 0, Loop = 1 };
	enum AnimDir { Horizontal = 0, Vertical = 1 };
	
	AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed = false);
	~AnimatedTexture();
	
	void SetWrapMode(WrapMode mode);
	void ResetAnimation();
	bool IsAnimating();
	
	void Update();

private:
	Timer * mTimer;
	int mStartX;
	int mStartY;
	
	int mFrameCount;
	
	float mAnimationSpeed;
	float mTimerPerFrame;
	float mAnimationTimer;
	
	WrapMode mWrapMode;
	AnimDir mAnimationDirection;
	
	bool mAnimationDone;
};

}

#endif /* AnimatedTexture_h */
