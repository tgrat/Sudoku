class Group;
class Grid;

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
	bool update();
	void clear();
};

void Cell::write(int val)
{
	if (val < 0 || val > 9)
	{
		throw "Value not in allowed range!\n";
	}
	value = val;
	clear();
	if (val!=0)
	{
		row[val-1] = true;
		col[val-1] = true;
		block[val-1] = true;
	}
	return;
}

bool Cell::update()
{	
	clear();
	for (int i = 0; i < 9; ++i)
	{	
		if (!block[i] && !row[i] && !col[i])
		{
			// std::cout << "Reach 1";
			poss[nposs] = i+1;
			++nposs;
		}
	};
	if (nposs == 1)
	{
		try
		{
			write(poss[0]);
		}
		catch(char const* msg){std::cout << msg;}
		return true;
	}
	return false;
}

void Cell::clear()
{
		nposs = 0;
		for (int i = 0; i < 9; ++i)
		{
			poss[i] = 0;
		}
}