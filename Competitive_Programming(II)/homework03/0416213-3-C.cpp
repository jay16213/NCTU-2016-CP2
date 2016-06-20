#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;

#define ON 'O'
#define OFF '#'
#define edge 10

void Enum_result(char grid[edge][edge], char save[edge][edge], int n, int k, int last, int &min_times);

int main()
{
	string Casename;
	char grid[edge][edge];
	char save[edge][edge];

	while (cin >> Casename && Casename != "end")
	{
		bool dont_switch = true;
		int min_times = 101;

		for (int i = 0; i < edge; i++)
			for (int j = 0; j < edge; j++)
			{
				cin >> grid[i][j];
				save[i][j] = grid[i][j];
				if (dont_switch && grid[i][j] == ON) dont_switch = false;
			}
		
		cout << Casename << " ";
		if (dont_switch) cout << "0" << endl;
		else
		{
			for (int n = 0; n <= edge; n++) 
				Enum_result(grid, save, n, 0, 0, min_times);

			if (min_times == 101) cout << "-1" << endl;
			else cout << min_times << endl;
		}
	}
	return 0;
}

bool All_Light_is_off(char grid[edge][edge])
{//because we turn off lights of last row in every row,we we need to only check the final row
	for (int i = 0; i < edge; i++)
		if (grid[9][i] == ON) return false;
	
	return true;
}


void Switch_Light(char grid[edge][edge], int x, int y)
{
	if (grid[x][y] == ON) grid[x][y] = OFF;//center
	else grid[x][y] = ON;

	if ((y + 1) < edge)//right
	{
		if (grid[x][y + 1] == ON) grid[x][y + 1] = OFF;
		else grid[x][y + 1] = ON;
	}

	if ((y - 1) >= 0)//left
	{
		if (grid[x][y - 1] == ON) grid[x][y - 1] = OFF;
		else grid[x][y - 1] = ON;
	}

	if ((x + 1) < edge)//down
	{
		if (grid[x + 1][y] == ON) grid[x + 1][y] = OFF;
		else grid[x + 1][y] = ON;
	}

	if ((x - 1) >= 0)//up
	{
		if (grid[x - 1][y] == ON) grid[x - 1][y] = OFF;
		else grid[x - 1][y] = ON;
	}
}

void init(char grid[edge][edge], char save[edge][edge])
{
	for (int i = 0; i < edge; i++)
	for (int j = 0; j < edge; j++)
		grid[i][j] = save[i][j];
}

void Enum_result(char grid[edge][edge], char save[edge][edge], int n, int k, int last, int  &min_times)
{
	static bool pushed[edge] = { false };
	static set<int> cor;
	//k records how many lights in first row we have switch
	//n records how many lights in first row should be switched in this time
	if (k == n)
	{
		int times = n;
		for (int row = 1; row < edge; row++)
			for (int j = 0; j < edge; j++)
			{
				if (grid[row - 1][j] == OFF) continue;

				Switch_Light(grid, row, j);
				times++;
			}
		if (All_Light_is_off(grid) && (times < min_times)) min_times = times;
		init(grid, save);//because the grid changes after every enum,we need initilize the grid.
		return;
	}

	for (int i = last; i < edge; i++)
	{
		if (pushed[i]) continue;

		pushed[i] = true;
		cor.insert(i);
		Switch_Light(grid, 0, i);

		Enum_result(grid, save, n, k + 1, i, min_times);

		pushed[i] = false;
		cor.erase(i);
		//after init grid,we need to restore the status which we have enumed in the last Recursion depth 
		for (set<int>::iterator it  = cor.begin(); it  != cor.end(); it++)
			Switch_Light(grid, 0, *it);
	}
	init(grid, save);//initilize the grid
	return;
}