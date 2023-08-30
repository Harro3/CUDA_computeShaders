#include "shader.hh"

// This is the global shader object, you can use it to interract with SFML for example
Shader shader;

void callback(int x, int y, double seconds, color &c) 
{
    // This is the callback, it is called for every pixel every frame
    (void)seconds;

    c.r = (float)x / (float)shader.width();
    c.g = (float)y / (float)shader.height(); 
} 

int main()
{
    // Here you can set the propperties of the shader
    shader
        .width(1000)
        .height(1000)
        .framerate(60)
        .callback(callback)
        .run();
}