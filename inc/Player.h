#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"


typedef struct Player
{
  Vector2 m_position;
  Vector2 m_direction;
  float m_rotation;
  Vector2 m_velocity;
  Vector2 m_acceleration;
  Texture m_texture;
  float m_maxAcceleration;
  float m_maxVelocity;
  float m_rateVelocity;
  float m_rateAcceleration;
} Player;

Player* CreatePlayer();

int DestroyPlayer(Player* player);

void UpdatePlayer(Player* player);

void RenderPlayer(Player* player);

void InitPlayer(Player* player,
                float posX,
                float posY,
                float velX,
                float velY,                
                float accelX,
                float accelY,
                float maxVelocity,
                float maxAccel,
                float rateVelocity,
                float rateAcceleration,
                const char* texturePath);



#endif // !PLAYER_H

