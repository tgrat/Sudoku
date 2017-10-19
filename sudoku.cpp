#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <iomanip>

#include "sudoku.h"


int main(int argc, char const *argv[])
{
	Cell cell[81];
	Grid grid(cell);
	// Group block[9];
	// Group row[9];
	// Group col[9];
	// Stack stack;

	grid.initCells();

	// char fileName[] = argv[1];
	try
	{
		grid.initGrid(argv[1]);
	}
	catch(char const* msg)
	{
		std::cout << msg << std::endl;
		return 1;
	}
	std::cout << "Initial Grid:\n";
	grid.printGrid(0);

	int iter = 0;
	bool change;
	bool complete;
	do
	{
		complete = true;
		// change = false;
		// std::cout << "Iteration " << iter << std::endl;
		for (int i = 0; i < 81; ++i)
		{	
			if (cell[i].value == 0)
			{
				complete = false;
				cell[i].update();
			}
		}
		++iter;
		// std::cout << ++iter << std::endl;
		// grid.printGrid(1);
		// grid.printGroup(0,1);
		// grid.printGroup(1,1);
		// grid.printGroup(2,1);
	} while (!complete && iter < 100);

	std::cout << "End grid after " << iter << " iterations" << std::endl;
	
	grid.printGrid(0);
	grid.printGrid(1);
	grid.printGrid(2);

	return 0;
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
	return;
};

void Grid::initCells()
{

	for (int i = 0; i < 81; ++i)
	{
		cell[i].col = &c[(i%9)*9];
		cell[i].row = &r[(i/9)*9];
		cell[i].block = &b[(((i/9)/3)*3 + (i%9)/3)*9];
	}
	return;
}

void Grid::initGrid(char const* fileName)
{
	std::ifstream file(fileName);
    // while (file)

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
    	throw "Error opening file!";
		// std::cout << "Error opening file!\n";
    }
    return;
}

void Grid::printGrid(int type)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			switch (type)
			{
				case 0:
					std::cout << cell[i*9+j].value << " ";
					break;
				case 1:
					std::cout << cell[i*9+j].nposs << " ";
					break;
				case 2:
					// std::cout << std::left <<std::setw(6) << "0";
					for (int k = 0; k < 9; ++k)
					{
						std::cout << cell[i*9+j].poss[k];
					}
					std::cout << " ";
					break;

			}
			if ((j+1)%3==0)
			{
				std::cout << "| ";
			}
		}
		if ((i+1)%3==0)
		{
			std::cout << "\n------|-------|-------|";
		}
		std::cout << "\n";
	}		
	std::cout << "\n";
	return;
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
	return;
}

void Cell::update()
{	
	clear();
	for (int i = 0; i < 9; ++i)
	{	
		if (!block[i] && !row[i] && !col[i])
		{
			poss[nposs] = i+1;
			++nposs;
		}
	};
	if (nposs == 1)
	{
		std::cout << "Set cell value!\n";
		write(poss[0]);
		return;
	}
	return;
}

// void Grid::insuff()
// {

// }

void Cell::write(int val)
{
	if (val < 0 || val > 9)
	{
		throw "Value not in allowed range!\n";
	}
	value = val;
	if (val!=0)
	{
		row[val-1] = true;
		col[val-1] = true;
		block[val-1] = true;
	}
	return;
}

void Cell::clear()
{

		nposs = 0;
		for (int i = 0; i < 9; ++i)
		{
			poss[i] = 0;
		}
}

// void Stack::push(Cell cell)
// {
// 	this-> cell[n][81] = cell;
// 	++n;
// }

// Cell Stack::pop()
// {
// 	return cell[n--][81];
// }