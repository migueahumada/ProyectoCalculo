#include <stdio.h>
#include "raylib.h"

int main ()
{
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  
  InitWindow(800, 600, "Hello Raylib");

  Texture wabbit = LoadTexture("wabbit_alpha.png"); //Esto no cargará
  

  while (!WindowShouldClose())
  {
    
    BeginDrawing();

    ClearBackground(BLACK);

    
    DrawText("Puto El Que lo Lea", 200,200,20,WHITE);

    DrawTexture(wabbit, 400, 200, WHITE);
    
    EndDrawing();
  }

  UnloadTexture(wabbit);

  CloseWindow();
  return 0;
}
