#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Utils.h"

typedef struct TextureProps
{
  Vector2   m_origin;
  Rectangle m_sourceRec;
  Rectangle m_destRec;
  Texture   m_texture;
  float     m_rotation;
  Color     m_tint;
} TextureProps;

typedef struct Player
{
  Vector2   m_position;
  float     m_rotation;
  TextureProps m_textureProps;
} Player;

//CREACION DESTRUCCIÓN
Player* CreatePlayer();

int DestroyPlayer(Player* player);

void InitPlayer(Player* player,
  float posX,
  float posY,
  const char* texturePath);

void UpdatePlayer(Player* player);

void RenderPlayer(Player* player);

//FUNCIONALIDADES

void SetPlayerPosition(Player* player, Vector2 position);

const Vector2 GetPlayerPosition(Player* player);

const Vector2 GetPlayerForwardVector(Player* player);

const Vector2 GetPlayerRightVector(Player* player);



#endif // !PLAYER_H

