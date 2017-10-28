#include "Window.h"
#include <iostream>
#include <SDL_image.h>

window::window(int width, int height) :
	_width(width), _height(height)
{
	_closed = !init();
}

window::~window()
{
	SDL_DestroyTexture(_texture);
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

bool window::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Failed to initialize SDL. \n";
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "Failed to initialize IMG. \n";
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, NULL);
	if (_window == nullptr)
	{
		std::cerr << "Failed to ctreate window. \n";
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		std::cerr << "Failed to ctreate renderer. \n";
		return false;
	}

	_surface = IMG_Load("res/3.png");
	if (_surface == nullptr)
	{
		std::cout << "Loading error.\n";
		return false;
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	SDL_FreeSurface(_surface);
	if (_texture == nullptr)
	{
		std::cout << "Creating error.\n";
		return false;
	}

	return true;
}

void window::load()
{
	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _texture, NULL, NULL);
}

void window::pollevents(SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		_closed = true; break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			_closed = true; break;
		}
	default: break;
	}
}
