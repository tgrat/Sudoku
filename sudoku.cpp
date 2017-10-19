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
	// Gr block[9], row[9], col[9];

	grid.initCells();

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
		for (int i = 0; i < 81; ++i)
		{	
			if (cell[i].value == 0)
			{
				complete = false;
				cell[i].update();
			}
		}
		++iter;
	} while (!complete && iter < 100);

	std::cout << "End grid after " << iter << " iterations" << std::endl;
	
	grid.printGrid(0);
	grid.printGrid(1);
	grid.printGrid(2);

	return 0;
}

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
			std::cout << "\n------+-------+-------+";
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
			// std::cout << "Reach 1";
			poss[nposs] = i+1;
			++nposs;
		}
	};
	if (nposs == 1)
	{
		write(poss[0]);
		return;
	}
	return;
}

void Cell::write(int val)
{
	if (val < 0 || val > 9)
	{
		throw "Value not in allowed range!\n";
	}
		std::cout << "Set cell value!" << val << "\n";
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

void Grid::insuff(int block, int row, int col)
{
	int count[9] = {0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				if(cell[block*((((i/9)/3) + (i%9)/3)) + row*(i+j*9)].nposs = k)
				{
					++count[k];
				}
			}
		}
	}
	for (int k = 0; k < 9; ++k)
	{
		if (count[k] == k)
		{
			
		}
	}
}