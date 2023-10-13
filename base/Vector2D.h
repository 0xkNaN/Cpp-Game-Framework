#ifndef __VECTOR_2D__
#define __VECTOR_2D__

#include <cmath>

class Vector2D
{
public:
  Vector2D(float x, float y) : x(x), y(y) {}

  float getX() { return x; }
  float getY() { return y; }

  void setX(float x) { this->x = x; }
  void setY(float y) { this->y = y; }

  float length() { return sqrt(x * x + y * y); }

  Vector2D operator+(const Vector2D &v2) const
  {
    return Vector2D(x + v2.x, y + v2.y);
  }

  friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2)
  {
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
  }

  Vector2D operator*(float s)
  {
    return Vector2D(x * s, y * s);
  }

  Vector2D &operator*=(float s)
  {
    x *= s;
    y *= s;
    return *this;
  }

  Vector2D operator-(const Vector2D &v2) const
  {
    return Vector2D(x - v2.x, y - v2.y);
  }

  friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2)
  {
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
  }

  Vector2D operator/(float s)
  {
    return Vector2D(x / s, y / s);
  }

  Vector2D &operator/=(float s)
  {
    x /= s;
    y /= s;
    return *this;
  }

  void normalize()
  {
    float l = length();
    if (l > 0)
    {
      (*this) *= 1 / l;
    }
  }

private:
  float x;
  float y;
};

#endif