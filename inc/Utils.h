#ifndef UTILS_H
#define UTILS_H

#include <raylib.h>

//ERRORES
typedef enum C_RESULT
{
  C_OK = 0,
  C_PLAYER_NOT_ALLOCATED = 1,
  C_PLAYER_NOT_DESTROYED = 2,
  C_PLAYER_TEXTURE_NOT_FOUND = 3

}C_RESULT;

void GetResult(int result);

Vector2 GetRightVector2();

Vector2 GetUpVector2();


/*
*   
  v1 | x | x | x |  
  v2 | x | x | x |
  v3 | x | x | x | traslation
*/

//Es Row-Major
typedef struct Matrix3
{
  Vector2 v1;
  Vector2 v2;
  Vector2 v3;
} Matrix3;

typedef struct WVP
{
  Matrix3 world;
  Matrix3 view;
  Matrix3 projection;
}WVP;



#endif // !UTILS_H


