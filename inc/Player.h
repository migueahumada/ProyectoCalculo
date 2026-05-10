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

void InitPlayer(Player* player,
                Vector2 position,
                Vector2 velocity,
                Vector2 acceleration, 
                const char* texturePath)
{
  
}

void InitPlayerPosition(Player* player, float x, float y)
{
  player->m_position.x = x;
  player->m_position.y = y;
}

void PlayerSetPosition(Player* player, Vector2 newPosition)
{
  player->m_position = newPosition;
}

Vector2 PlayerGetPosition(Player* player, Vector2 newPosition)
{
  return player->m_position;
}