#ifndef CMATH_H
#define CMATH_H

#define FORCEINLINE __forceinline
  
  struct CVector2f
  {
    CVector2f() = default;
    CVector2f(float _x = 0, float _y = 0) : x(_x), y(_y){}

    inline CVector2f operator+(const CVector2f& rhs)
    {
      return CVector2f{x + rhs.x,
                       y + rhs.y};
    }

    inline CVector2f operator-(const CVector2f& rhs)
    {
      return CVector2f{ x - rhs.x,
                        y - rhs.y};
    }

    inline CVector2f operator*(float scalar)
    {
      return CVector2f{ x * scalar,
                        y * scalar};
    }

    inline CVector2f dot(const CVector2f& rhs)
    {
      return CVector2f{x * rhs.x + y * rhs.y };
    }

    inline CVector2f operator|(const CVector2f& rhs)
    {
      return CVector2f{ x * rhs.x + y * rhs.y };
    }

    float x = 0;
    float y = 0;
  };

#endif // !CMATH_H
