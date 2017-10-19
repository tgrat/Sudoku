
class Cell
{
public:
	Cell(){};
	Cell(bool* b, bool* r, bool* c): value(0) {};
	~Cell(){};

	int value;
	int nposs;
	bool poss[9];
	bool* block;
	bool* row;
	bool* col;

	void write(int val);
};

class Grid
{
public:
	Grid(Cell cell[81]) {this-> cell = cell;};
	~Grid(){};

	Cell* cell;
	bool b[81];
	bool r[81];
	bool c[81];

	void printGrid();
	void printBlock(int check);
	void initCells();
	void initGrid(char* fileName);
};


// class Group
// {
// public:
// 	bool has[9] = {false,false,false,false,false,false,false,false,false};
// };


// void initCells(Cell cell[], bool block[], bool row[], bool col[]);

// 	// void initGrid(Cell cell[]);
// 	void initGrid(char fileName[], Cell cell[]);
// 	// void printGrid(Cell cell[]);
// 	// void printBlock(Group test[], int check);