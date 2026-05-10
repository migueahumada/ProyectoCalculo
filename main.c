#include <stdio.h>
#include "raylib.h"

// FUNCIONES BASES
void Init();
void Update(float deltaTime);
void Render();
void Shutdown();

//VARIABLES GLOBALES
Texture wabbit;

//COMIENZA PROGAMA
int main ()
{
  Init();

  while (!WindowShouldClose())
  {
    Update(0.0f);

    Render();
  }

  Shutdown();
  return 0;
}

void Init()
{
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);


  InitWindow(800, 600, "Hello Raylib");

  wabbit = LoadTexture("D:/Rex_C.png"); 
}

void Update(float deltaTime)
{
  
}

void Render()
{
  BeginDrawing();

  ClearBackground(BLUE);

  DrawText("Puto El Que lo Lea", 200, 200, 20, WHITE);

  DrawTexture(wabbit, 400, 200, WHITE);

  EndDrawing();
}

void Shutdown()
{
  UnloadTexture(wabbit);
  CloseWindow();
}