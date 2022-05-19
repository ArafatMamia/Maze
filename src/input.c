#include "../headers/header.h"
void SDL_KEYDOWN_FUNC(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		gameRunning = false;
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = +1;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = -1;
}

void SDL_KEYUP_FUNC(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = 0;
}

void handleInput(void)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		gameRunning = false;
	else if (event.type == SDL_KEYDOWN)
		SDL_KEYDOWN_FUNC(event);
	else if (event.type == SDL_KEYUP)
		SDL_KEYUP_FUNC(event);
	

	
}
