class Cell;

class Grid
{
public:
	Grid();
	~Grid();

	Cell cell[81];
	bool block[81];
	bool row[81];
	bool col[81];

	void printGrid();
};

class Cell: public Grid
{
public:
	Cell();
	Cell(bool* b, bool* r, bool* c): value(0) {};
	~Cell();

	int value;
	// bool* block;
	// bool* row;
	// bool* col;

	void write(int val);
};




class Group
{
public:
	bool has[9] = {false,false,false,false,false,false,false,false,false};
};


void initCells(Cell cell[], bool block[], bool row[], bool col[]);

	// void initGrid(Cell cell[]);
	void initGrid(char fileName[], Cell cell[]);
	// void printGrid(Cell cell[]);
	// void printBlock(Group test[], int check);