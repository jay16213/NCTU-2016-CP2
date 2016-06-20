#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct coord{
	int x;
	int y;
	friend istream& operator>>(istream& in, coord& coordinate)
	{
		in >> coordinate.x >> coordinate.y;
		return in;
	}
};

double getDistance(coord first,coord second)
{
	double dx = first.x - second.x;
	double dy = first.y - second.y;
	return sqrt( dx * dx + dy * dy );
}

int main()
{
	for (int testcase = 1, n; cin >> n && n; testcase++)
	{
		vector<vector<double> > path(n, vector<double>(n));
		vector<coord> point(n);
		coord start, destination;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				path[i][j] = 0x3FFFFFFF;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> point[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				path[i][j] = getDistance(point[i],point[j]);
			}
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					path[i][j] = min(path[i][j],max(path[i][k], path[k][j]));
			}
		}

		//output answer
		printf("Scenario #%d\n", testcase);
		printf("Frog Distance = %.3f\n\n", path[0][1]);
	}
	//system("pause");
	return 0;
}