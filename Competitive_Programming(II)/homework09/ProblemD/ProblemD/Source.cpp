#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 0x3FFFFFFF

int no_path = 0, neg_cycle = 0, has_path = 0;

struct edge{
	int u, v, w;
};

void foo(int start, vector<vector<int> > &w, int n)
{
	vector<int> d(n + 1, MAX);
	vector<bool> inS(n + 1, false);
	d[start] = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1, minD = MAX;

		for (int j = 1; j <= n; j++)
		{
			if (!inS[j] && d[j] < minD)
			{
				u = j;
				minD = d[j];
			}
		}

		if (u == -1) break;
		inS[u] = true;

		for (int v = 1; v <= n; v++)
		{
			if (w[u][v] == MAX) continue;

			if (d[u] + w[u][v] < d[v])
				d[v] = d[u] + w[u][v];
		}
	}

	for (int u = 1; u <= n; u++)
	{
		if (d[u] == MAX)
		{
			no_path++;
			continue;
		}
		for (int v = 1; v <= n; v++)
		{
			if (w[u][v] != MAX && d[v] > d[u] + w[u][v])
			{
				//printf("(%d %d) has neg cycle pass through %d\n",start,v,u);
				d[v] = d[u] + w[u][v];
				neg_cycle++;
			}
		}
	}
}

void func(int start, vector<vector<edge> > &E, int n)
{
	vector<int> d(n + 1, MAX);
	vector<bool> inS(n + 1, false);
	d[start] = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1, minD = MAX;

		for (int j = 1; j <= n; j++)
		{
			if (!inS[j] && d[j] < minD)
			{
				u = j;
				minD = d[j];
			}
		}

		if (u == -1) break;
		inS[u] = true;

		for (int j = 0; j < E[u].size(); j++)
		{
			int v = E[u][j].v, w = E[u][j].w;
			if (d[u] + w < d[v])
				d[v] = d[u] + w;
		}
	}

	for (int u = 1; u <= n; u++)
	{
		if (d[u] == MAX)
		{
			no_path++;
			//continue;
		}
		for (int j = 0; j < E[u].size(); j++)
		{
			int v = E[u][j].v, w = E[u][j].w;
			if (d[u] + w < d[v])
			{
				neg_cycle++;
				d[v] = d[u] + w;
			}
		}
	}
}

int all_pairs(int n){ return n*(n - 1) + n; }

int main()
{
	int testcase;
	scanf_s("%d", &testcase);
	while (testcase--)
	{
		int n, m;
		no_path = 0, neg_cycle = 0, has_path = 0;
		scanf_s("%d %d", &n, &m);

		vector<vector<edge> > E(n + 1, vector<edge>());

		for (int i = 0; i < m; i++)
		{
			edge in;
			scanf_s("%d %d %d", &in.u, &in.v, &in.w);
			E[in.u].push_back(in);
		}

		for (int i = 1; i <= n; i++)
		{
			func(i,E,n);
			//Shorted_path(i, w, n);
		}

		printf("%d %d %d\n", no_path, neg_cycle, all_pairs(n) - neg_cycle - no_path);
	}
	system("pause");
	return 0;
}
