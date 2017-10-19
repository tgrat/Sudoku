class Cell
{
public:
	int value = 0;
	int blockID;
	int rowID;
	int colID;
};

class Group
{
public:
	bool has[9] = {false,false,false,false,false,false,false,false,false};
};

void initCells(Cell cell[]);
void initGrid(Cell cell[]);
void initGrid(char fileName[], Cell cell[], Group block[], Group row[], Group col[]);
void printGrid(Cell cell[]);
void printBlock(Group test[], int check);
bool updateCell(Cell &cell,Group block[], Group row[], Group col[]);