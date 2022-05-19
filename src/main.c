#include "..headers/header.h"

bool gameRunning = false;
int TicksLastFrame = 0;
player_t player;

void update_game(void)
{
	float DeltaTime;
	int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeToWait);
	}
	DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;

	TicksLastFrame = SDL_GetTicks();

	movePlayer(DeltaTime);
}

void setup_game(void)
{

	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 10;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
	player.turnDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
}

void render_game(void)
{


	renderMap();
	renderRays();
	renderPlayer();

	renderColorBuffer();
}

int main(void)
{
	gameRunning = initializeWindow();
	setup_game();

	while (gameRunning)

	{
		handleInput();
		update_game();
		render_game();
		
	}
	destroyWindow();
	return (0);
}
