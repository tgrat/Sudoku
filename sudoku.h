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

class Grid
{
public:
	Grid(Cell cell[81]);
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
	void insuff();
};

// class Group
// {
// public:
// 	Group(): fill(0) {};
// 	~Group(){};
	
// 	Cell* cell[9];
// 	int fill;
// };

// class Stack
// {
// public:
// 	Stack(): n(0) {};
// 	~Stack(){};

// 	int n;
// 	Cell cell[100][81];
	
// 	void push(Cell cell);
// 	Cell pop();
// };
