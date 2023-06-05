#include "../lib/shader.hh"

// height and width for perfect squares
const int width = 700;
const int height = 700;

color palette(float t)
{
    color a = color{0.5, 0.5, 0.5, 1.0};
    color b = color{0.5, 0.5, 0.5, 1.0};
    color c = color{1.0, 1.0, 1.0, 1.0};
    color d = color{0.263, 0.416, 0.557, 1.0};

    return palette(t, a, b, c, d);
}

void callback(int x, int y, double seconds, color &c)
{
    vec2 uv = (vec2{(float)x,(float)y} * 2.0 - vec2{width, height}) / (float)height;

    vec2 uv0 = uv;
    uv.x *= (float)width / (float)height;

    color final_color = color{0.0, 0.0, 0.0, 1.0};

    for (int i = 0; i < 4; i++)
    {
        uv = fract(uv * 1.5) - 0.5;
        float d = length(uv) * exp(-length(uv0));

        color col = palette(length(uv0) + i * 0.4 + seconds * 0.4);

        d = sin(d * 8.0 + seconds) / 8.0;

        d = std::abs(d);

        d = pow(0.01 / d, 2);

        final_color += col *= d;

    }

    c = final_color;
}

int main()
{
    Shader shader;
    shader.width(width).height(height).callback(callback).framerate(60);

    shader.run();
    return 0;
}