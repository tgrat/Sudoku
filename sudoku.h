class Cell
{
public:
	Cell(){clear();};
	~Cell(){};

	int value;
	int nposs;
	int poss[9];
	bool* block;
	bool* row;
	bool* col;

	void write(int val);
	void update();
	void clear();
};

// class Gr
// {
// public:
// 	Gr()
// 	{
// 		for (int i = 0; i < 9; ++i)
// 		{
// 			has[i] = false;
// 		}
// 	};
// 	~Gr(){};
	
// 	Cell cell[9];
// 	bool has[9];	
// };

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

	void printGrid(int type);
	void printGrid(bool poss);
	void printGroup(int type, int check);
	void initCells();
	void initGrid(char const* fileName);
	void insuff(int block, int row, int col);
};

