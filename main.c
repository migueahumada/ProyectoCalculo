#include <stdio.h>
#include "raylib.h"
#include "inc/Player.h"
#include <stdlib.h>

//ERRORES
enum CALC_RESULT
{
  PLAYER_NOT_ALLOCATED = 1
};

// FUNCIONES BASES
void Init();
void Update(float deltaTime);
void Render();
void Shutdown();
void Input();

//VARIABLES GLOBALES
Texture Car;
const int screenWidth = 1200;
const int screenHeight = 800;
Vector2 ballPosition;
struct Player* g_Player;

//COMIENZA PROGAMA
int main ()
{
  Init();
  
  while (!WindowShouldClose())
  {
    SetTargetFPS(60);
    Update(0.0f);
    Input();
    Render();
  }

  Shutdown();
  return 0;
}

void Init()
{
  SetConfigFlags(FLAG_VSYNC_HINT);
  
  InitWindow(screenWidth, screenHeight, "Hello Raylib");
  ballPosition.x = (float)screenWidth / 2;
  ballPosition.y = (float)screenHeight / 2;

  g_Player = malloc(sizeof(struct Player));

  if (!g_Player)
  {
    printf("ERROR PLAYER NOT ALLOCATED");
  }

  InitPlayerPosition(g_Player, 230, 230);
  Car = LoadTexture("rsc/Panther.png");
  int A = 2;
}

void Update(float deltaTime)
{
  
}

void Input() {
    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
}

void Render()
{
  BeginDrawing();

  ClearBackground(GRAY);

  DrawText("Puto El Que lo Lea", 200, 200, 20, WHITE);

  DrawCircleV(ballPosition, 50, MAGENTA);
  Vector2 POS;
  POS.x = 300;
  POS.y = 300;
  DrawTextureV(Car, POS, RED);

  EndDrawing();
}

void Shutdown()
{
  free(g_Player);
  UnloadTexture(Car);
  CloseWindow();
}
