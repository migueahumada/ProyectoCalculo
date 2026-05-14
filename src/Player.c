#include "Player.h"
#include <stdlib.h>
#include "Utils.h"
#include <string.h>
#include <raymath.h>


Player* CreatePlayer()
{
  Player* player = malloc(sizeof(Player));
  if (!player)
  {
    return NULL;
  }

  memset(player, 0, sizeof(Player));

  return player;
}

int DestroyPlayer(Player* player)
{
  if (player)
  {
    UnloadTexture(player->m_textureProps.m_texture);
    free(player);
    return C_OK;
  }
  else
  {
    return C_PLAYER_NOT_DESTROYED;
  }
}

//Constructor
void InitPlayer(Player* player,
                float posX,
                float posY,
                const char* texturePath)
{
  
  //Textura usada
  player->m_textureProps.m_texture = LoadTexture(texturePath);

  //Rectángulo donde se dibuja la imagen
  player->m_textureProps.m_sourceRec = (Rectangle)
  {
      0,
      0,
      player->m_textureProps.m_texture.width,
      player->m_textureProps.m_texture.height,
  };

  player->m_position.x = posX;
  player->m_position.y = posY;

  //Rectángulo destino
  player->m_textureProps.m_destRec = (Rectangle)
  {
    posX, 
    posY, 
    player->m_textureProps.m_texture.width,
    player->m_textureProps.m_texture.height
  };

  player->m_textureProps.m_origin.x = player->m_textureProps.m_texture.width / 2.0f ;
  player->m_textureProps.m_origin.y = player->m_textureProps.m_texture.height / 2.0f;

  player->m_rotation = 0;

  player->m_textureProps.m_tint = WHITE;
}

void UpdatePlayer(Player* player)
{
  
  player->m_textureProps.m_destRec.x = player->m_position.x;
  player->m_textureProps.m_destRec.y = player->m_position.y;
  
}

void RenderPlayer(Player* player)
{
  /*DrawRectangle(player->m_textureProps.m_destRec.x - player->m_textureProps.m_destRec.width/2,
                player->m_textureProps.m_destRec.y - player->m_textureProps.m_destRec.height/2,
                player->m_textureProps.m_destRec.width,
                player->m_textureProps.m_destRec.height,
                WHITE);*/
  

  //Dibujar Coche
  DrawTexturePro(player->m_textureProps.m_texture,
                 player->m_textureProps.m_sourceRec,
                 player->m_textureProps.m_destRec,
                 player->m_textureProps.m_origin,
                 player->m_rotation * RAD2DEG,
                 player->m_textureProps.m_tint);
}

void SetPlayerPosition(Player* player, Vector2 position)
{
  if (player == NULL)
  {
    return;
  }

  player->m_position = position;

}

const Vector2 GetPlayerPosition(Player* player)
{
  if (player == NULL)
  {
    return (Vector2) { 0, 0 };
  }

  return player->m_position;
}

const Vector2 GetPlayerForwardVector(Player* player)
{
  return (Vector2) {
    cosf(player->m_rotation + (DEG2RAD * 270)),
    sinf(player->m_rotation + (DEG2RAD * 270))
  };
}

const Vector2 GetPlayerRightVector(Player* player)
{
  return (Vector2) {
    cosf(player->m_rotation * DEG2RAD),
    sinf(player->m_rotation * DEG2RAD)
  };
}
