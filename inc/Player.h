#pragma once
#include "raymath.h"

typedef struct Player
{
  Vector2 position;
  Vector2 velocity;
  Vector2 acceleration;
} Player;

void InitPlayerPosition(Player* player, float x, float y)
{
  player->position.x = x;
  player->position.y = y;
}

void PlayerSetPosition(Player* player, Vector2 newPosition)
{
  player->position = newPosition;
}

Vector2 PlayerGetPosition(Player* player, Vector2 newPosition)
{
  return player->position;
}