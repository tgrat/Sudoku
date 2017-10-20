#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <iomanip>

#include"sudoku.h"
#include "cell.h"
// #include "group.h"
#include "grid.h"

int main(int argc, char const *argv[])
{
	Cell cell[81];
	Grid grid(cell);

	grid.initCells();

	try
	{
		grid.initGrid(argv[1]);
	}
	catch(char const* msg){std::cout << msg << std::endl; return 1;}
	std::cout << "Initial Grid:\n";
	grid.printGrid(VALUE);
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
				change = cell[i].update();
			}
		}
		++iter;
	} while (!complete && iter < 100);

	std::cout << "End grid after " << iter << " iterations" << std::endl;
	
	grid.printGrid(VALUE);
	// grid.printGrid(NPOSS);
	// grid.printGrid(POSS);

	return 0;
}