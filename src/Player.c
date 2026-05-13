#include "Player.h"
#include <stdlib.h>
#include "Utils.h"
#include <string.h>



//Constructor
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
                const char* texturePath)
{
  player->m_position.x = posX;
  player->m_position.y = posY;
  player->m_velocity.x = velX;
  player->m_velocity.y = velY;
  player->m_acceleration.x = accelX;
  player->m_acceleration.y = accelY;
  player->m_maxVelocity = maxVelocity;
  player->m_maxAcceleration = maxAccel;
  player->m_rateVelocity = rateVelocity;
  player->m_rateAcceleration = rateAcceleration;
  player->m_texture = LoadTexture(texturePath);
}



Player* CreatePlayer()
{
  Player* player = malloc(sizeof(Player));
  if (!player)
  {
    return NULL;
  }

  memset(player,0,sizeof(Player));

  return player;
}

int DestroyPlayer(Player* player)
{
  if (player)
  {
    UnloadTexture(player->m_texture);
    free(player);
    return C_OK;
  }else
  {
    return C_PLAYER_NOT_DESTROYED;
  }
}

void UpdatePlayer(Player* player)
{
  
}

void RenderPlayer(Player* player)
{
  DrawTextureEx(player->m_texture,
                player->m_position,
                player->m_rotation,
                3.0f, WHITE);
}

