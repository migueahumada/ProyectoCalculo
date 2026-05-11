#include <stdio.h>
#include "Player.h"
#include <stdlib.h>
#include "Utils.h"


// FUNCIONES BASES
void Init();
void Update();
void Render();
void Shutdown();
void Input();

//VARIABLES GLOBALES

const int screenWidth = 1200;
const int screenHeight = 800;
Vector2 ballPosition;
Player* g_Player;
C_RESULT result;

//COMIENZA PROGAMA
int main ()
{
  Init();
  
  while (!WindowShouldClose())
  {
    SetTargetFPS(60);
    Update();
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
  
  g_Player = CreatePlayer();
  if (g_Player == NULL)
  {
    printf("Error with number: %d", C_PLAYER_NOT_ALLOCATED);
  }

  InitPlayer(g_Player,300,100,
             300,300,
             500,500,
             400, 800,
             "../rsc/Panther.png");
}

void Update()
{
  
}

void Input() {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
      g_Player->m_velocity.x += g_Player->m_acceleration.x * GetFrameTime();
      g_Player->m_position.x += g_Player->m_velocity.x * GetFrameTime();
      
    } 
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
      g_Player->m_velocity.x -= g_Player->m_acceleration.x * GetFrameTime();
      g_Player->m_position.x -= g_Player->m_velocity.x * GetFrameTime();
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
      g_Player->m_position.y -= g_Player->m_velocity.y * GetFrameTime();
      g_Player->m_velocity.y -= 100;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
      g_Player->m_position.y += g_Player->m_velocity.y * GetFrameTime();
      g_Player->m_velocity.y += 100;
    }
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
  result = DestroyPlayer(g_Player);
  CloseWindow();
}
