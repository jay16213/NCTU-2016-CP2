#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

class coordinate{
//this class combines 2D-coordinate (x,y) into an object,
//and it overloads some operators which will be useful in this program.
public:
	int x;
	int y;

	coordinate(){}
	coordinate(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	bool operator<(const coordinate& input) const{ return x < input.x && y < input.y; }
	bool operator>=(const coordinate& input) { return x >= input.x && y >= input.y; }
	bool operator==(const coordinate& input) { return x == input.x && y == input.y; }
	bool operator!=(const coordinate& input) { return x != input.x || y != input.y; }
	coordinate operator+=(const coordinate& input)
	{
		x += input.x;
		y += input.y;
		return *this;
	}
	coordinate operator-=(const coordinate& input)
	{
		x -= input.x;
		y -= input.y;
		return *this;
	}
};

coordinate direction[4];//the 4 directions of treaten,and it is initialzed in the main function
vector<coordinate> queen;//stores the coordinates of queen

bool FindQueen(coordinate c)//check if there is a queen at (c.x,c.y)
{
	for (int i = 0; i < queen.size(); i++) { if (c == queen[i]) return true; }

	return false;
}

void Change_Treaten(int treaten[8][8], coordinate coord, int k)
{
	treaten[coord.x][coord.y] += k;
	for (int i = 0; i < 4; i++)
	{
		//from left to right,top to bottom
		for (coordinate c(coord.x, coord.y); c < coordinate(8, 8) && c >= coordinate(0, 0); c += direction[i])
			if (!FindQueen(c) && c != coord) treaten[c.x][c.y] += k;

		//from right to left,bottom to top
		for (coordinate c(coord.x, coord.y); c < coordinate(8, 8) && c >= coordinate(0, 0); c -= direction[i])
			if (!FindQueen(c) && c != coord) treaten[c.x][c.y] += k;
	}
}

void BFS(int &ans, int board[8][8], int treaten[8][8], int row)
{
	if (row == 8)
	{
		int sum = 0;
		for (auto it = queen.begin(); it != queen.end(); it++)
			sum += board[it->x][it->y];

		if (sum > ans) ans = sum;
		return;
	}

	for (coordinate i(row, 0); i < coordinate(row + 1, 8); i += coordinate(0, 1))
	{
		if (treaten[i.x][i.y]) continue;

		queen.push_back(i);
		Change_Treaten(treaten, i, 1);

		BFS(ans, board, treaten, row + 1);

		queen.pop_back();
		Change_Treaten(treaten, i, -1);
	}

	return;
}

int main()
{//four direction:horizontal,vertical and 2 diagonals
	direction[0].x = 0; direction[0].y = 1;
	direction[1].x = 1; direction[1].y = 0;
	direction[2].x = 1; direction[2].y = 1;
	direction[3].x = 1; direction[3].y = -1;

	int k;
	cin >> k;
	while (k--)
	{
		int board[8][8] = { 0 };
		int treaten[8][8] = { 0 };
		int ans = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				scanf("%d", &board[i][j]);
		}

		BFS(ans, board, treaten, 0);
		printf("%5d\n", ans);
	}
	return 0;
}