#include "Player.h"
#include <stdlib.h>
#include "Utils.h"
#include <string.h>
#include <raymath.h>




//Constructor
void InitPlayer(Player* player,
                float posX,
                float posY,
                const char* texturePath)
{
  player->m_position.x = posX;
  player->m_position.y = posY;

  player->m_texture = LoadTexture(texturePath);

  player->m_origin.x = player->m_texture.width / 2.0f;
  player->m_origin.y = player->m_texture.height / 2.0f;

  player->m_sourceRec = (Rectangle)
  {
      0,
      0,
      player->m_texture.width,
      player->m_texture.height,
  };

  player->m_destRec.width = player->m_texture.width;
  player->m_destRec.height = player->m_texture.height;

  player->m_destRec.x = player->m_position.x - player->m_origin.x;
  player->m_destRec.y = player->m_position.y - player->m_origin.y;

  player->m_rotation = 0;

  player->m_tint = WHITE;
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
  DrawRectangle(player->m_destRec.x - player->m_destRec.width/2,
                player->m_destRec.y- player->m_destRec.height/2,
    player->m_destRec.width,
    player->m_destRec.height,
    WHITE);

  DrawTexturePro(player->m_texture,
    player->m_sourceRec,
    player->m_destRec,
    player->m_origin,
    player->m_rotation,
    player->m_tint);
}
