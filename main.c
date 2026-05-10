#include <stdio.h>
#include "raylib.h"

// FUNCIONES BASES
void Init();
void Update(float deltaTime);
void Render();
void Shutdown();
void Input();

//VARIABLES GLOBALES
Texture wabbit;
const int screenWidth = 1200;
const int screenHeight = 800;
Vector2 ballPosition;

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

  wabbit = LoadTexture("D:/Rex_C.png"); 
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

  DrawTexture(wabbit, 400, 200, WHITE);

  DrawCircleV(ballPosition, 50, MAGENTA);

  EndDrawing();
}

void Shutdown()
{
  UnloadTexture(wabbit);
  CloseWindow();
}
