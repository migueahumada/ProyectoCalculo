#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player
{
  Vector2 m_position;
  Vector2 m_rotation;
  Vector2 m_velocity;
  Vector2 m_acceleration;
  Texture m_texture;
  float maxAcceleration;
  float maxVelocity;
} Player;

Player* CreatePlayer();

int DestroyPlayer(Player* player);

void InitPlayer(Player* player,
                float posX,
                float posY,
                float velX,
                float velY,                
                float accelX,
                float accelY,
                float maxVelocity,
                float maxAccel,
                const char* texturePath);



#endif // !PLAYER_H

