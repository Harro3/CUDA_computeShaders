#include "../config.hh"

#include "shader.hh"

void callback(int x, int y, double seconds, color &c)
{
    (void)x;
    (void)y;
    (void)seconds;
    c = color{0.0, 0.0, 0.0, 1.0};
}