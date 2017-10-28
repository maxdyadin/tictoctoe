#include "elements.h"
#include "Grid.h"
#include "GridItem.h"
#include <SDL_image.h>
#include <iostream>
#include <string>

elements::elements(const window & window, Grid & grid)
	: window(window), grid(grid)
{
	_xosurf1 = IMG_Load("res/1.png");
	_xosurf2 = IMG_Load("res/2.png");
	if (_xosurf1 == nullptr || _xosurf2 == nullptr)
	{
		std::cout << "Failed to create surf.\n";
	}
	
	_xotex1 = SDL_CreateTextureFromSurface(_renderer, _xosurf1);
	_xotex2 = SDL_CreateTextureFromSurface(_renderer, _xosurf2);
	if (_xotex1 == nullptr || _xotex2 == nullptr)
	{
		std::cout << "Failed to create texture.\n";
	}
	SDL_FreeSurface(_xosurf1);
	SDL_FreeSurface(_xosurf2);
}

elements::~elements()
{
	SDL_DestroyTexture(_xotex1);
	SDL_DestroyTexture(_xotex2);
}

void elements::draw()
{
	GridItem *ngrid = grid.getarray();
	for (int i = 0; i < 9; i++)
	{
		if (ngrid[i].value != 0)
		{
			int x = ngrid[i].x;
			int y = ngrid[i].y;
			if (ngrid[i].value == 1) { _tex = _xotex1; }
			else { _tex = _xotex2; }
			SDL_Rect rect = { x, y, 160, 160 };
			SDL_RenderCopy(_renderer, _tex, NULL, &rect);
		}
	}
}

int currplayer = 1;

void elements::pollevents(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_KP_7:
			if (grid.check(0)) {
				if (currplayer == 1) { grid.setX(0, 20, 20); _switch(); }
				else { grid.setO(0, 20, 20); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_8:
			if (grid.check(1)) {
				if (currplayer == 1) { grid.setX(1, 220, 20); _switch(); }
				else { grid.setO(1, 220, 20); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_9:
			if (grid.check(2)) {
				if (currplayer == 1) { grid.setX(2, 420, 20); _switch(); }
				else { grid.setO(2, 420, 20); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_4:
			if (grid.check(3)) {
				if (currplayer == 1) { grid.setX(3, 20, 220); _switch(); }
				else { grid.setO(3, 20, 220); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_5:
			if (grid.check(4)) {
				if (currplayer == 1) { grid.setX(4, 220, 220); _switch(); }
				else { grid.setO(4, 220, 220); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_6:
			if (grid.check(5)) {
				if (currplayer == 1) { grid.setX(5, 420, 220); _switch(); }
				else { grid.setO(5, 420, 220); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_1:
			if (grid.check(6)) {
				if (currplayer == 1) { grid.setX(6, 20, 420); _switch(); }
				else { grid.setO(6, 20, 420); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_2:
			if (grid.check(7)) {
				if (currplayer == 1) { grid.setX(7, 220, 420); _switch(); }
				else { grid.setO(7, 220, 420); _switch(); }
			}
			else break;
			break;

		case SDLK_KP_3:
			if (grid.check(8)) {
				if (currplayer == 1) { grid.setX(8, 420, 420); _switch(); }
				else { grid.setO(8, 420, 420); _switch(); }
			}
			else break;
			break;

		case SDLK_ESCAPE:
			_closed = true; break;

		default: break;
		}
	}
}
void elements::_switch()
{
	if (currplayer == 1) 
	{
		currplayer = 2;
	}
	else currplayer = 1;
}