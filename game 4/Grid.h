#pragma once
#include"GridItem.h"

class Grid
{
public:
	Grid();
	~Grid();
	void init();
	bool check(int i);
	GridItem* getarray();
	void setX(int i, int x, int y);
	void setO(int i, int x, int y);

	int GameOver();
	void GameOverHandle();

	int over;
	int x=0;
	int y=0;
	SDL_Texture *texture=nullptr;
};

