#include <stdio.h>
#include "Player.h"
#include <stdlib.h>
#include "Utils.h"
#include <raymath.h>
#include <rlgl.h>


// FUNCIONES BASES
void Init();
void Update();
void Render();
void Shutdown();
void Input();

//VARIABLES GLOBALES

const int screenWidth = 1200;
const int screenHeight = 800;
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
  
  g_Player = CreatePlayer();
  if (g_Player == NULL)
  {
    printf("Error with number: %d", C_PLAYER_NOT_ALLOCATED);
  }
  
  InitPlayer(g_Player,
             300,100,
             "../rsc/Panther.png");
}

void Update()
{
  UpdatePlayer(g_Player);
}

void Input() {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
      
      g_Player->m_rotation++;
      
    } 
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
      g_Player->m_rotation--;
      //g_Player->m_origin = Vector2Rotate(g_Player->m_origin, 3);
      
      
    }
  
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
      g_Player->m_origin = Vector2Add(g_Player->m_origin, GetUpVector2());
      
      
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
      
      g_Player->m_origin = Vector2Subtract(g_Player->m_origin, GetUpVector2());
      
    }
}

void Render()
{
  BeginDrawing();

  ClearBackground(GRAY);
 
  RenderPlayer(g_Player);
  

  EndDrawing();
}

void Shutdown()
{
  result = DestroyPlayer(g_Player);
  CloseWindow();
}
