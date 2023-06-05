#include "shader_functions.hh"

#include <cmath>

double clamp(double a, double b, double c)
{
    return std::fmax(b, std::fmin(c, a));
}

int step(double a, double b)
{
    return a > b ? 0 : 1;
}

double smoothstep(double a, double b, double c)
{
    double t = clamp((c - a) / (b - a), 0.0, 1.0);
    return t * t * (3.0 - 2.0 * t);
}

color palette(double t, color a, color b, color c, color d)
{
    color res = 6.28318 * (t*c + d);
    res = color{cosf(res.r), cosf(res.g), cosf(res.b), 1.0};
    res = a + b * res;
    return res;
}

float fract(float a)
{
    return a - std::floor(a);
}

vec2 fract(vec2 a)
{
    return vec2{fract(a.x), fract(a.y)};
}