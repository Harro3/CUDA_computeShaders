#include "shader_frames.hh"
#include <math.h>

color operator+(const color &a, const color &b)
{
    color c;
    c.r = a.r + b.r;
    c.g = a.g + b.g;
    c.b = a.b + b.b;
    c.a = a.a + b.a;
    return c;
}

color operator-(const color &a, const color &b)
{
    color c;
    c.r = a.r - b.r;
    c.g = a.g - b.g;
    c.b = a.b - b.b;
    c.a = a.a - b.a;
    return c;
}

color operator*(const color &a, const color &b)
{
    color c;
    c.r = a.r * b.r;
    c.g = a.g * b.g;
    c.b = a.b * b.b;
    c.a = a.a * b.a;
    return c;
}

color operator/(const color &a, const color &b)
{
    color c;
    c.r = a.r / b.r;
    c.g = a.g / b.g;
    c.b = a.b / b.b;
    c.a = a.a / b.a;
    return c;
}

color operator+(color &a, const float &b)
{
    color c;
    c.r = a.r + b;
    c.g = a.g + b;
    c.b = a.b + b;
    c.a = a.a + b;
    return c;
}

color operator-(color &a, const float &b)
{
    color c;
    c.r = a.r - b;
    c.g = a.g - b;
    c.b = a.b - b;
    c.a = a.a - b;
    return c;
}

color operator*(color &a, const float &b)
{
    color c;
    c.r = a.r * b;
    c.g = a.g * b;
    c.b = a.b * b;
    c.a = a.a * b;
    return c;
}

color operator/(color &a, const float &b)
{
    color c;
    c.r = a.r / b;
    c.g = a.g / b;
    c.b = a.b / b;
    c.a = a.a / b;
    return c;
}

color operator+(float a, const color &b)
{
    color c;
    c.r = a + b.r;
    c.g = a + b.g;
    c.b = a + b.b;
    c.a = a + b.a;
    return c;
}

color operator-(float a, const color &b)
{
    color c;
    c.r = a - b.r;
    c.g = a - b.g;
    c.b = a - b.b;
    c.a = a - b.a;
    return c;
}

color operator*(float a, const color &b)
{
    color c;
    c.r = a * b.r;
    c.g = a * b.g;
    c.b = a * b.b;
    c.a = a * b.a;
    return c;
}

color operator/(float a, const color &b)
{
    color c;
    c.r = a / b.r;
    c.g = a / b.g;
    c.b = a / b.b;
    c.a = a / b.a;
    return c;
}

color operator+=(color &a, const color &b)
{
    a.r += b.r;
    a.g += b.g;
    a.b += b.b;
    a.a += b.a;
    return a;
}

color operator-=(color &a, const color &b)
{
    a.r -= b.r;
    a.g -= b.g;
    a.b -= b.b;
    a.a -= b.a;
    return a;
}

color operator*=(color &a, const color &b)
{
    a.r *= b.r;
    a.g *= b.g;
    a.b *= b.b;
    a.a *= b.a;
    return a;
}

color operator/=(color &a, const color &b)
{
    a.r /= b.r;
    a.g /= b.g;
    a.b /= b.b;
    a.a /= b.a;
    return a;
}

color operator+=(color &a, const float &b)
{
    a.r += b;
    a.g += b;
    a.b += b;
    a.a += b;
    return a;
}

color operator-=(color &a, const float &b)
{
    a.r -= b;
    a.g -= b;
    a.b -= b;
    a.a -= b;
    return a;
}

color operator*=(color &a, const float &b)
{
    a.r *= b;
    a.g *= b;
    a.b *= b;
    a.a *= b;
    return a;
}

color operator/=(color &a, const float &b)
{
    a.r /= b;
    a.g /= b;
    a.b /= b;
    a.a /= b;
    return a;
}

vec2 operator+(const vec2 &a, const vec2 &b)
{
    vec2 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

vec2 operator-(const vec2 &a, const vec2 &b)
{
    vec2 c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

vec2 operator*(const vec2 &a, const vec2 &b)
{
    vec2 c;
    c.x = a.x * b.x;
    c.y = a.y * b.y;
    return c;
}

vec2 operator/(const vec2 &a, const vec2 &b)
{
    vec2 c;
    c.x = a.x / b.x;
    c.y = a.y / b.y;
    return c;
}

vec2 operator+(const vec2 &a, const float &b)
{
    vec2 c;
    c.x = a.x + b;
    c.y = a.y + b;
    return c;
}

vec2 operator-(const vec2 &a, const float &b)
{
    vec2 c;
    c.x = a.x - b;
    c.y = a.y - b;
    return c;
}

vec2 operator*(const vec2 &a, const float &b)
{
    vec2 c;
    c.x = a.x * b;
    c.y = a.y * b;
    return c;
}

vec2 operator/(const vec2 &a, const float &b)
{
    vec2 c;
    c.x = a.x / b;
    c.y = a.y / b;
    return c;
}

vec2 operator--(const vec2 &a)
{
    vec2 c;
    c.x = -a.x;
    c.y = -a.y;
    return c;
}

vec2 operator++(const vec2 &a)
{
    vec2 c;
    c.x = +a.x;
    c.y = +a.y;
    return c;
}

vec2 operator-=(vec2 &a, const vec2 &b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

vec2 operator+=(vec2 &a, const vec2 &b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

vec2 operator*=(vec2 &a, const vec2 &b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

vec2 operator/=(vec2 &a, const vec2 &b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

vec2 operator+=(vec2 &a, const float &b)
{
    a.x += b;
    a.y += b;
    return a;
}

vec2 operator-=(vec2 &a, const float &b)
{
    a.x -= b;
    a.y -= b;
    return a;
}

vec2 operator*=(vec2 &a, const float &b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

vec2 operator/=(vec2 &a, const float &b)
{
    a.x /= b;
    a.y /= b;
    return a;
}

float length(const vec2 &a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}