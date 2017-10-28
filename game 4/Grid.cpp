#include "Grid.h"
#include <SDL.h>
#include <iostream>

GridItem grid[9];

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::init()
{
	for (int i = 0; i < 9; i++)
	{
		grid[i].x = 0;
		grid[i].y = 0;
		grid[i].value = 0;
	}
}

bool Grid::check(int i)
{
	if (grid[i].value == 0) return true;
	else return false;
}

void Grid::setX(int i, int x, int y)
{
	grid[i].value = 1;
	grid[i].x = x;
	grid[i].y = y;
}

void Grid::setO(int i, int x, int y)
{
	grid[i].value = 2;
	grid[i].x = x;
	grid[i].y = y;
}

GridItem* Grid::getarray() 
{
	return grid;
}

//int Grid::GameOver()
//{
//	for (int i = 1; i < 3; i++)
//	{
//		if
//			    ((grid[1].value == i && grid[2].value == i && grid[3].value == i) ||
//				(grid[4].value == i && grid[5].value == i && grid[6].value == i) ||
//				(grid[7].value == i && grid[8].value == i && grid[9].value == i) ||
//
//				(grid[1].value == i && grid[4].value == i && grid[7].value == i) ||
//				(grid[2].value == i && grid[5].value == i && grid[8].value == i) ||
//				(grid[3].value == i && grid[6].value == i && grid[9].value == i) ||
//
//				(grid[1].value == i && grid[5].value == i && grid[9].value == i) ||
//				(grid[3].value == i && grid[5].value == i && grid[7].value == i))
//
//			over = i;
//	}
//
//	int count=1;
//	for (int j = 0; j < 9; j++)
//	{
//		if (grid[j].value != 0) count++;
//	}
//	if (count == 9) { over = 0; }
//	return 0;
//}
//
//void Grid::GameOverHandle()
//{
//	switch (over)
//	{
//	case 0: std::cout << "Draw!"; break;
//	case 1: std::cout << "Crosses won!"; break;
//	case 2: std::cout << "Cirecles won!"; break;
//	}
//}