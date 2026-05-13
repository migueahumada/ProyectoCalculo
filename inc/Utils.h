#ifndef UTILS_H
#define UTILS_H

#include <raylib.h>

//ERRORES
typedef enum C_RESULT
{
  C_OK = 0,
  C_PLAYER_NOT_ALLOCATED = 1,
  C_PLAYER_NOT_DESTROYED = 2,

}C_RESULT;

void GetResult(int result);

Vector2 GetRightVector2();

Vector2 GetUpVector2();


#endif // !UTILS_H


