#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
extern bool gameRunning;
bool initializeWindow(void);
void destroyWindow(void);

#define NUM_TEXTURES 8
#define PI 3.14159265
#define TWO_PI 6.28318530
#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define MINIMAP_SCALE_FACTOR 0.996
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)
#define NUM_RAYS SCREEN_WIDTH
#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))
#define FOV_ANGLE (60 * (PI / 180))
typedef uint32_t color_t;
void handleInput(void);
void renderMap(void);
void renderColorBuffer(void);
void render_game(void);
void drawPixel(int x, int y, color_t color);
void drawRect(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);
bool DetectCollision(float x, float y);

typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} player_t;

extern player_t player;
typedef struct ray_s
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];
void renderRays(void);
void movePlayer(float DeltaTime);
void renderPlayer(void);
void renderMap(void);
void renderRays(void);
#endif
