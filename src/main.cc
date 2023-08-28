#include "shader.hh"

#include "shaders/config.hh"
 
int main()
{
    Shader shader;
    shader.width(width).height(height).callback(callback).framerate(framerate);

    shader.run();
    return 0;
}