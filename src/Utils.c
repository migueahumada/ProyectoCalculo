#include "Utils.h"

void GetResult(int result)
{
  const char* ResultErrors[128] =
  {
    "C_OK",
    "C_PLAYER_NOT_ALLOCATED",
    "C_PLAYER_NOT_DESTROYED"
  };
}

Vector2 GetRightVector2()
{
  Vector2 result;
  
  result.x = 1.0f;
  result.y = 0.0f;
  
  return result;
}

Vector2 GetUpVector2()
{
  Vector2 result;
  
  result.x = 0.0f;
  result.y = 1.0f;
  
  return result;
}
