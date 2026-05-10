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

  int foo = 3;

  //PLAYER INIT
  g_Player = malloc(sizeof(struct Player));

  if (!g_Player)
  {
    printf("ERROR PLAYER NOT ALLOCATED");
  }

  InitPlayer(g_Player,300, 100,200,200,8,8, "../rsc/Panther.png");
}

void Update(float deltaTime)
{
  
}

void Input() {
    if (IsKeyDown(KEY_RIGHT)) g_Player->m_position.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) g_Player->m_position.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) g_Player->m_position.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) g_Player->m_position.y += 2.0f;
}

void Render()
{
  BeginDrawing();

  ClearBackground(GRAY);

  DrawText("Puto El Que lo Lea", 200, 200, 20, WHITE);
 
  DrawTextureV(g_Player->m_texture, g_Player->m_position, WHITE);

  EndDrawing();
}

void Shutdown()
{
  ShutDownPlayer(g_Player);
  free(g_Player);
  CloseWindow();
}
