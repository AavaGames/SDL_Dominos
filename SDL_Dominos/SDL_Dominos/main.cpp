//
//  main.cpp
//  SDL_Tutorial
//
//  Created by Philip Fertsman on 2020-01-14.
//  Copyright © 2020 Philip Fertsman. All rights reserved.
//

#include "Managers/GameManager.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */

using SDLFramework::GameManager;

int main(int argc, char * args[])
{
	srand(time(NULL));
	GameManager * game = new GameManager();
	
	game->Run();
	
	GameManager::Release();
	game = nullptr;
	
	return 0;
}
