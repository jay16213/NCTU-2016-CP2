#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

string Target = "111110111100 110000100000";
int ans = 0;
bool finished = false;

vector<string> board;
int dir_x[] = { -2, -2, 2, 2, -1, 1, -1, 1 };
int dir_y[] = { -1, 1, -1, 1, -2, -2, 2, 2 };

string change2Dto1D()
{
	string c;
	for (int i = 0; i < 5; i++)
	{
		c += board[i];
	}
	return c;
}

int Diff()
{
	int cnt = 0;
	string check = change2Dto1D();
	for (int i = 0; i < 25; i++)
	{
		if (check[i] != Target[i]) cnt++;
	}
	return cnt;
}

void DFS(int depth, int empty_x, int empty_y)
{
	int k = Diff();
	if (depth >= ans)
	{
		if (Target.compare(change2Dto1D()) == 0)
		{
			finished = true;
		}
		return;
	}

	if (depth + k / 2 > ans) return;

	for (int i = 0; i < 8 && !finished; i++)
	{
		int Go_x = empty_x + dir_x[i];
		int Go_y = empty_y + dir_y[i];
		if (Go_x < 0 || Go_x >= 5 || Go_y < 0 || Go_y >= 5) continue;

		swap(board[Go_x][Go_y], board[empty_x][empty_y]);
		DFS(depth + 1, Go_x, Go_y);
		swap(board[Go_x][Go_y], board[empty_x][empty_y]);
	}
	return;
}
int main()
{
	int testcase;
	cin >> testcase;
	getchar();
	while (testcase--)
	{
		finished = false;
		int empty_x, empty_y;
		for (int i = 0; i < 5; i++)
		{
			string input;
			getline(cin, input);
			for (int j = 0; j < 5; j++)
			{
				if (input[j] == ' ')
				{
					empty_x = i;
					empty_y = j;
				}
			}
			board.push_back(input);
		}

		for (ans = 0; ans <= 10; ans++)
		{
			DFS(0, empty_x, empty_y);
			if (finished) break;
		}

		if (finished) printf("Solvable in %d move(s).\n", ans);
		else printf("Unsolvable in less than 11 move(s).\n");
		board.clear();
	}
	return 0;
}