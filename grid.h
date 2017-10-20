class Cell;
class Group;

class Grid
{
public:
	Grid(Cell cell[81])
	{
		this-> cell = cell;	
		for (int i = 0; i < 81; ++i)
		{
			b[i] = false;
			r[i] = false;
			c[i] = false;
		}
	};
	~Grid(){};

	Cell* cell;
	bool b[81];
	bool r[81];
	bool c[81];

	void initCells();
	void initGrid(char const* fileName);
	void printGrid(int type);
	void printGroup(int type, int check);
};

void Grid::initCells()
{

	for (int i = 0; i < 81; ++i)
	{
		cell[i].block = &b[(((i/9)/3)*3 + (i%9)/3)*9];
		cell[i].row = &r[(i/9)*9];
		cell[i].col = &c[(i%9)*9];
	}
	return;
}

void Grid::initGrid(char const* fileName)
{
	std::ifstream file(fileName);

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
				case VALUE:
					std::cout << cell[i*9+j].value << " ";
					break;
				case NPOSS:
					std::cout << cell[i*9+j].nposs << " ";
					break;
				case POSS:
					for (int k = 0; k < 9; ++k){std::cout << cell[i*9+j].poss[k];}
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
		case BLOCK:
			std::cout << "Testing blocks for " << check << std::endl;
			break;
		case ROW:
			std::cout << "Testing rows for " << check << std::endl;
			break;
		case COL:
			std::cout << "Testing columns for " << check << std::endl;
			break;
	}
	for (int i = 0; i < 81; ++i)
	{
		switch (type)
		{
			case BLOCK: 
				std::cout << cell[i].block[check-1];
				break;
			case ROW:
				std::cout << cell[i].row[check-1];
				break;
			case COL:
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