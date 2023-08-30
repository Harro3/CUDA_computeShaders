#include "shader.hh"

#include <iostream>
#include <cstdint>
#include <sys/types.h>

#include <chrono>
#include <thread>

Shader::Shader()
{
	screen_width_ = 100;
	screen_height_ = 100;
	framerate_ = 120;

	callback_ = [](int, int, double, color &) -> void
	{
	};
}

Shader &Shader::width(int width)
{
	screen_width_ = width;
	return *this;
}

Shader &Shader::height(int height)
{
	screen_height_ = height;
	return *this;
}

Shader &Shader::framerate(int framerate)
{
	framerate_ = framerate;
	return *this;
}

Shader &Shader::callback(void (*callback) (int x, int y, double seconds, color &c))
{
	callback_ = callback;
	return *this;
}

Shader &Shader::run()
{

    // create the window
	window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(screen_width_, screen_height_), "Shader");
	window_->setFramerateLimit(framerate_);

    // create a texture
    sf::Texture texture;
    texture.create(screen_width_, screen_height_);

    // Create a pixel buffer to fill with RGBA data
    unsigned char* pixbuff = new unsigned char[screen_width_ * screen_height_ * 4];
    // Create uint32_t pointer to above for easy access as RGBA
    uint32_t * intptr = (uint32_t *)pixbuff;

    // run the program as long as the window is open
    int frame = 0;

	int nb_threads = std::thread::hardware_concurrency();

	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    while (window_->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window_->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
			{
                window_->close();
			}
		}
		window_->clear();

		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration_cast<std::chrono::duration<double>>(now - begin).count();

		int nb_pixels_per_thread = screen_width_ * screen_height_ / nb_threads;

		std::vector<std::thread> threads;

		for (int i = 0; i < nb_threads; i++)
		{
			threads.push_back(std::thread([=]()
			{
				for (int j = 0; j < nb_pixels_per_thread; j++)
				{
					int x = (j + i * nb_pixels_per_thread) % screen_width_;
					int y = (j + i * nb_pixels_per_thread) / screen_width_;

					y = screen_height_ - y;
					color c = {0, 0, 0, 1};
					callback_(x, y, seconds, c);

					unsigned char r = round(clamp(c.r, 0.0, 1.0) * 255);
					unsigned char g = round(clamp(c.g, 0.0, 1.0) * 255);
					unsigned char b = round(clamp(c.b, 0.0, 1.0) * 255);
					unsigned char a = round(clamp(c.a, 0.0, 1.0) * 255);

 					intptr[j + i * nb_pixels_per_thread] = (a << 24) | (b << 16) | (g << 8) | r;
				}
			}));
		}

		for (int i = 0; i < nb_threads; i++)
		{
			threads[i].join();
		}

		frame++;

		// update the texture
		texture.update(pixbuff);
		sf::Sprite sprite(texture);
		window_->draw(sprite);

		// end the current frame
		window_->display();

			
	}
	

	return *this;
}