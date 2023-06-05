#pragma once

#include <iostream>

#include "shader_frames.hh"
#include "shader_functions.hh"

class Shader
{
public:
    Shader();

    Shader &width(int width);

    Shader &height(int height);

    Shader &framerate(int framerate);

    Shader &callback(void (*callback) (int x, int y, double seconds, color& c));

    Shader &run();

private:
    int screen_width_;
    int screen_height_;
    int framerate_;

    void (*callback_) (int x, int y, double seconds, color& c);
};