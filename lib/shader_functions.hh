#pragma once

#include "shader_frames.hh"

double clamp(double a, double b, double c);

int step(double a, double b);

double smoothstep(double a, double b, double c);

color palette(double t, color a, color b, color c, color d);

float fract(float a);

vec2 fract(vec2 a);