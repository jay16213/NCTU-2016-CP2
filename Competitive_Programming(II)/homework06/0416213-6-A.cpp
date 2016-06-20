#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int input[100][100];
	int sum[100][100] = { 0 };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> input[i][j];

	sum[0][0] = input[0][0];
	for (int j = 1; j < N; j++)	sum[0][j] = sum[0][j - 1] + input[0][j];//prefix sum of first row
	for (int i = 1; i < N; i++) sum[i][0] = sum[i - 1][0] + input[i][0];//prefix sum of first column

	//compute prefix sum
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + input[i][j] - sum[i - 1][j - 1];
	}

	int Max = sum[0][0];
	//rectangle which left-up is (0,0) and right-bottom is (i,j)
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (sum[i][j] > Max) Max = sum[i][j];
	}

	//rectangle which left-up is (x1,y1) and right-bottom is (x2,y2)
	for (int x1 = 0, y1 = 1; x1 < N && y1 < N; y1++)
	{
		for (int x2 = x1, y2 = y1; x2 < N && y2 < N; y2++)
		{
			int t;
			if (x1 - 1 < 0) t = sum[x2][y2] - sum[x2][y1 - 1];
			else if (y1 - 1 < 0) t = sum[x2][y2] - sum[x1 - 1][y2];
			else t = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

			if (t > Max) Max = t;

			if (y2 == N - 1)
			{
				x2++;
				y2 = y1-1;
			}
		}

		if (y1 == N - 1)
		{
			x1++;
			y1 = -1;
		}
	}

	cout << Max << endl;
	return 0;
}