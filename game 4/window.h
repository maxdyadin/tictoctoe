#pragma once
#include <SDL.h>
#include <string>

class window
{
public:
	window(int width, int height);
	~window();

	void pollevents(SDL_Event &event);
	void load();
	inline bool isclosed() const { return _closed; }

private:
	bool init();
	std::string _title;
	int _width = 800;
	int _height = 600;
	SDL_Window *_window = nullptr;
	SDL_Texture *_texture = nullptr;
	SDL_Surface *_surface = nullptr;

protected:
	SDL_Renderer *_renderer = nullptr;
	bool _closed = false;
};