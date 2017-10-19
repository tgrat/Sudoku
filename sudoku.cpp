#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
// #include <string>

#include "sudoku.h"


int main(int argc, char const *argv[])
{
	Cell cell[81];
	Grid grid(cell);

	grid.initCells();

	char fileName[] = "test1";
	grid.initGrid(fileName);
	std::cout << "Initial Grid:\n";
	grid.printGrid();

	int iter = 0;
	bool change;
	do
	{
		change = false;
		// std::cout << "Iteration " << iter << std::endl;
		for (int i = 0; i < 81; ++i)
		{	
			if (cell[i].value == 0)
			{
				change = cell[i].update();
			}
		}
		std::cout << ++iter << std::endl;
		grid.printGrid();
		grid.printGroup(0,1);
		grid.printGroup(1,1);
		grid.printGroup(2,1);
	} while (change);

	std::cout << iter << std::endl;
	grid.printGrid();


}

Grid::Grid(Cell cell[81])
{
	this-> cell = cell;	
	for (int i = 0; i < 81; ++i)
	{
		b[i] = false;
		r[i] = false;
		c[i] = false;
	}
};

void Grid::initCells()
{

	for (int i = 0; i < 81; ++i)
	{
		cell[i].col = &c[(i%9)*9];
		cell[i].row = &r[(i/9)*9];
		cell[i].block = &b[(((i/9)/3)*3 + (i%9)/3)*9];
	}
}

void Grid::initGrid(char* fileName)
{
	std::ifstream file(fileName);
    while (file)
    if(file.is_open())
    {
		char c;
		int i = 0;
		while (file.get(c))
		{
			cell[i].write(c-'0');
			++i;
		}
			
    }
    else
    {
		std::cout << "Error opening file!";
    }
}

void Grid::printGrid()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			// std::cout << i*9+j << " ";
			std::cout << cell[i*9+j].value << " ";
			if ((j+1)%3==0)
			{
				std::cout << "|";
			}
		}
		if ((i+1)%3==0)
		{
			std::cout << "\n------|------|------|";
		}
		std::cout << "\n";
	}		
	std::cout << "\n";
}

void Grid::printGroup(int type, int check)
{
	switch(type)
	{
		case 0:
			std::cout << "Testing blocks for " << check << std::endl;
			break;
		case 1:
			std::cout << "Testing rows for " << check << std::endl;
			break;
		case 2:
			std::cout << "Testing columns for " << check << std::endl;
			break;
	}
	for (int i = 0; i < 81; ++i)
	{
		switch (type)
		{
			case 0: 
				std::cout << cell[i].block[check-1];
				break;
			case 1:
				std::cout << cell[i].row[check-1];
				break;
			case 2:
				std::cout << cell[i].col[check-1];
				break;
		}
		if ((i+1)%3 == 0)
		{
			std::cout << "|";
		}
		if ((i+1)%27 == 0)
		{
			std::cout << "\n---+---+---";
		}
		if ((i+1)%9 == 0)
		{
			std::cout << std::endl;
		}
	}
}

bool Cell::update()
{	
	int is;
	int poss = 0;
	for (int i = 0; i < 9; ++i)
	{	
		if (!block[i] && !row[i] && !col[i])
		{
			++poss;
			is = i;
		}
	};
	if (poss == 1)
	{
		write(is+1);
		return true;
	}
	return false;
}

void Cell::write(int val)
{
	value = val;
	if (val!=0)
	{
		row[val-1] = true;
		col[val-1] = true;
		block[val-1] = true;
	}
	return;
}