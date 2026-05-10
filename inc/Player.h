#pragma once
#include "raymath.h"
#include "raylib.h"

typedef struct Player
{
  Vector2 m_position;
  Vector2 m_rotation;
  Vector2 m_velocity;
  Vector2 m_acceleration;
  Texture m_texture;
} Player;

//Constructor
void InitPlayer(Player* player,
                float posX,
                float posY,
                float velX,
                float velY,
                float accelX,
                float accelY,
                const char* texturePath)
{
  player->m_position.x = posX;
  player->m_position.y = posY;
  player->m_velocity.x = velX;
  player->m_velocity.y = velY;
  player->m_acceleration.x = accelX;
  player->m_acceleration.y = accelY;
  player->m_texture = LoadTexture(texturePath);
}

//Destructor
void ShutDownPlayer(Player* player)
{
  UnloadTexture(player->m_texture);
}




void PlayerSetPosition(Player* player, Vector2 newPosition)
{
  player->m_position = newPosition;
}

Vector2 PlayerGetPosition(Player* player, Vector2 newPosition)
{
  return player->m_position;
}

void LoadPlayerTexture(Player* player, const char* texturePath)
{
  player->m_texture = LoadTexture(texturePath);
}

