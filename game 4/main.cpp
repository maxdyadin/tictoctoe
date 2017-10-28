#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "elements.h"
#include "Grid.h"

void mainWindowEventHadler(window &window, elements &elements)
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		elements.pollevents(event);
		window.pollevents(event);
	}
}

int main(int argc, char**argv)
{
	Grid grid;
	window window(800, 600);
	elements elements(window, grid);

	while (!window.isclosed())
	{
		elements.draw();
		mainWindowEventHadler(window, elements);
		window.load();
		/*grid.GameOver();
		grid.GameOverHandle();*/
	}

	return 0;
}