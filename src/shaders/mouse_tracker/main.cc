#include "shader.hh"

Shader shader;

// Global mouse position
sf::Vector2i mouse_position;

bool is_mouse_down = false;

void callback(int x, int y, double, color &c) 
{ 
    // Input gathering, the if statement is to make sure it only runs once per frame
    if (y == 1 && x == 1)
    {
        mouse_position = sf::Mouse::getPosition(shader.window());
        mouse_position.y = shader.height() - mouse_position.y;

        is_mouse_down = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }

    // calculate the distance from the mouse to the current pixel
    double dist_squared = (x - mouse_position.x) * (x - mouse_position.x) + (y - mouse_position.y) * (y - mouse_position.y);

    float gray = smoothstep(0, 50000, dist_squared);

    // Inverse the color if the mouse is down
    if (is_mouse_down)
        gray = 1.0 - gray;

    c = color{gray, gray, gray, 1.0};

}

int main()
{
    shader
        .width(1000)
        .height(1000)
        .framerate(50)
        .callback(callback)
        .run();
}