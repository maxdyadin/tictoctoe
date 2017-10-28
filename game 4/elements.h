#pragma once

#include "window.h"
#include <string>
#include "Grid.h"

class elements : public window
{
public:
		elements(const window & window, Grid & grid);
		~elements();
		void draw();
		void _switch ();
		void pollevents(SDL_Event &event);
		int _x, _y;

private:
	SDL_Texture *_xotex1 = nullptr;
	SDL_Texture *_xotex2 = nullptr;
	SDL_Texture *_tex = nullptr;
	SDL_Surface *_xosurf1 = nullptr;
	SDL_Surface *_xosurf2 = nullptr;
	Grid grid;
};
