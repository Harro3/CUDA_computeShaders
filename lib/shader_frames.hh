#pragma once

#include <cmath>

struct color
{
    float r;
    float g;
    float b;
    float a;
};

color operator+(const color &a, const color &b);
color operator-(const color &a, const color &b);
color operator*(const color &a, const color &b);
color operator/(const color &a, const color &b);

color operator+(const color &a, const float &b);
color operator-(const color &a, const float &b);
color operator*(const color &a, const float &b);
color operator/(const color &a, const float &b);

color operator+(float a, const color &b);
color operator-(float a, const color &b);
color operator*(float a, const color &b);
color operator/(float a, const color &b);

color operator+=(color &a, const color &b);
color operator-=(color &a, const color &b);
color operator*=(color &a, const color &b);
color operator/=(color &a, const color &b);

color operator+=(color &a, const float &b);
color operator-=(color &a, const float &b);
color operator*=(color &a, const float &b);
color operator/=(color &a, const float &b);

struct vec2
{
    float x;
    float y;
};

vec2 operator+(const vec2 &a, const vec2 &b);
vec2 operator-(const vec2 &a, const vec2 &b);
vec2 operator*(const vec2 &a, const vec2 &b);
vec2 operator/(const vec2 &a, const vec2 &b);

vec2 operator+(const vec2 &a, const float &b);
vec2 operator-(const vec2 &a, const float &b);
vec2 operator*(const vec2 &a, const float &b);
vec2 operator/(const vec2 &a, const float &b);

vec2 operator--(const vec2 &a);
vec2 operator++(const vec2 &a);

vec2 operator-= (vec2 &a, const vec2 &b);
vec2 operator+= (vec2 &a, const vec2 &b);
vec2 operator*= (vec2 &a, const vec2 &b);
vec2 operator/= (vec2 &a, const vec2 &b);

vec2 operator+=(vec2 &a, const float &b);
vec2 operator-=(vec2 &a, const float &b);
vec2 operator*=(vec2 &a, const float &b);

float length(const vec2 &a);