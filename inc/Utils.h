#ifndef UTILS_H
#define UTILS_H

//ERRORES
typedef enum C_RESULT
{
  C_OK = 0,
  C_PLAYER_NOT_ALLOCATED = 1,
  C_PLAYER_NOT_DESTROYED = 2,

}C_RESULT;

void GetResult(int result);

#endif // !UTILS_H


