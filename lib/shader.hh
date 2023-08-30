#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>


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

    int width() const
    {
        return screen_width_;
    }

    int height() const
    {
        return screen_height_;
    }

    int framerate() const
    {
        return framerate_;
    }

    sf::RenderWindow &window()
    {
        return *window_;
    }

private:
    int screen_width_;
    int screen_height_;
    int framerate_;

    std::shared_ptr<sf::RenderWindow> window_;

    void (*callback_) (int x, int y, double seconds, color& c);
};