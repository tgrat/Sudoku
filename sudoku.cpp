#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>

#include "sudoku.h"


int main(int argc, char const *argv[])
{
	Grid grid;
	// Cell cell[81];
	// bool block[81];
	// bool row[81];
	// bool col[81];

	initCells(grid.cell,block,row,col);

	char fileName[] = "test1";

	initGrid(fileName,grid.cell);
	std::cout << "Initial Grid:\n";
	grid.printGrid();

	// printBlock(block,2);

	int iter = 1;
	bool change;
	do
	{
		// std::cout << "Iteration " << iter << std::endl;
		for (int i = 0; i < 81; ++i)
		{	
			if (grid.cell[i].value == 0)
			{
				change = grid.cell.updateCell();
			}
		}
		++iter;
	} while (change);

	printGrid(cell);


}

void initCells(Cell cell[], bool block[], bool row[], bool col[])
{

	for (int i = 0; i < 81; ++i)
	{
		cell[i].col = &col[(i%9)*9];
		cell[i].row = &row[(i/9)*9];
		cell[i].block = &block[(((i/9)/3)*3 + (i%9)/3)*9];
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

void initGrid(char fileName[], Cell cell[])
{
	std::ifstream file(fileName);
    while (file)
    if(file.is_open())
    {
		char c;
		int i = 0;
		while (file.get(c))
		{
			cell[i].write(int(c-'0'));
			if (cell[i].value != 0)
			// {	
			// 	block[cell[i].blockID].has[cell[i].value-1] = true;
			// 	row[cell[i].rowID].has[cell[i].value-1] = true;
			// 	col[cell[i].colID].has[cell[i].value-1] = true;
			// }
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

void printBlock(Group test[], int check)
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

bool updateCell(Cell &cell,Group block[], Group row[], Group col[])
{
	int poss = 0;
	int is = 0;
	for (int i = 0; i < 9; ++i)
	{	
		if (!block[cell.blockID].has[i] && !row[cell.rowID].has[i] && !col[cell.colID].has[i])
		{
			++poss;
			is = i;
		}
	};
	if (poss == 1)
	{
		// std::cout << "Cell is defined\n";
		cell.write(is+1);
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

Grid::Grid()
{
	for (int i = 0; i < 81; ++i)
	{
		block[i] = false;
		row[i] = false;
		col[i] - false;
	};
}