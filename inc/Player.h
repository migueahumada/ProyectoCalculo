#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"


typedef struct Player
{
  Vector2   m_position;
  Vector2   m_origin;
  Rectangle m_sourceRec;
  Rectangle m_destRec;
  Texture   m_texture;
  float     m_rotation;
  Color     m_tint;
} Player;

Player* CreatePlayer();

int DestroyPlayer(Player* player);

void UpdatePlayer(Player* player);

void RenderPlayer(Player* player);

void InitPlayer(Player* player,
                float posX,
                float posY,
                const char* texturePath);



#endif // !PLAYER_H

