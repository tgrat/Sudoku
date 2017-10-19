#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>

#include "cell.h"
#include "grid.h"


int main(int argc, char const *argv[])
{
	Cell cell[81];
	Grid grid(cell);

	grid.initCells();

	char fileName[] = "test1";
	grid.initGrid(fileName);
	std::cout << "Initial Grid:\n";
	grid.printGrid();

	grid.printBlock(block,2);

	// int iter = 1;
	// bool change;
	// do
	// {
	// 	// std::cout << "Iteration " << iter << std::endl;
	// 	for (int i = 0; i < 81; ++i)
	// 	{	
	// 		if (grid.cell[i].value == 0)
	// 		{
	// 			change = grid.cell.updateCell();
	// 		}
	// 	}
	// 	++iter;
	// } while (change);

	// printGrid(cell);


}

void Grid::initCells()
{

	for (int i = 0; i < 81; ++i)
	{
		cell[i].col = &c[(i%9)*9];
		cell[i].row = &r[(i/9)*9];
		cell[i].block = &b[(((i/9)/3)*3 + (i%9)/3)*9];
	}
}

// void initGrid(Cell cell[])
// {
// 	for (int i = 0; i < 81; ++i)
// 	{
// 		printf("Row %i, Column %i\n",cell[i].rowID,cell[i].colID);
// 		std::cin.get() >> cell[i].value;
		
// 	}
// }

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

void Grid::printBlock(int check)
{
	std::cout << "Testing blocks for " << check << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << test[i*3+j].has[check-1] << " ";
			
		}
		std::cout << "\n";
	}
}

// bool updateCell(Cell &cell,Group block[], Group row[], Group col[])
// {
// 	int poss = 0;
// 	int is = 0;
// 	for (int i = 0; i < 9; ++i)
// 	{	
// 		if (!block[cell.blockID].has[i] && !row[cell.rowID].has[i] && !col[cell.colID].has[i])
// 		{
// 			++poss;
// 			is = i;
// 		}
// 	};
// 	if (poss == 1)
// 	{
// 		// std::cout << "Cell is defined\n";
// 		cell.write(is+1);
// 		return true;
// 	}
// 	return false;
// }

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