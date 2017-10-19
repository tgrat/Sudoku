class Cell
{
public:
	Cell(){};
	~Cell(){};

	int value;
	bool* block;
	bool* row;
	bool* col;

	void write(int val);
	bool update();
};

class Grid
{
public:
	Grid(Cell cell[81]);
	~Grid(){};

	Cell* cell;
	bool b[81];
	bool r[81];
	bool c[81];

	void printGrid();
	void printGrid(bool poss);
	void printGroup(int type, int check);
	void initCells();
	void initGrid(char* fileName);
};
