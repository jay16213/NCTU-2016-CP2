#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAX_INT 2147483647
struct edge{
	int u;
	int v;
};

int letterToint(char c)
{
	if (isupper(c)) return c - 'A';
	else return c - 'a' + 26;
}

bool isTown(int c){ return c < 26; }

int computeWeight(int p,int end)
{
	if (isTown(end))
		return (p / 20 + (p % 20 != 0));
	else 
		return 1;//village
}

void getData(int &p, int &start, int &end)
{
	string input;
	getline(cin, input);
	bool first = true;
	for (int i = 0; i < input.size(); i++)
	{
		while (isdigit(input[i]))
			p = p * 10 + (input[i++] - '0');

		if (isalpha(input[i]))
		{
			if (first) start = letterToint(input[i]);
			else end = letterToint(input[i]);
			first = false;
		}
	}
}

int main()
{
	int n,testcase = 1;
	while (cin >> n && n != -1)
	{
		fflush(stdin);
		vector<edge> edgelist;
		int start = 0, end = 0;
		int p = 0;

		for (int i = 0; i < n; i++)
		{
			string input;
			getline(cin, input);
			edge Edge;
			Edge.u = letterToint(input[0]);
			Edge.v = letterToint(input[2]);
			edgelist.push_back(Edge);
			swap(Edge.u,Edge.v);
			edgelist.push_back(Edge);
		}
		getData(p, start, end);
		

		vector<int> path(52, MAX_INT);
		path[start] = 0;

		int c = p;
		for (; path[end] != MAX_INT; c++)
		{
			for (int k = 0; k < edgelist.size() - 1;i++)
			{
				for (auto i : edgelist)
				{
					int w = computeWeight(c, i.v);
					if (c >= p + w)
					{
						if (path[i.u] + w < path[i.v])
						{
							path[i.v] = path[i.u] + w;
							c -= w;
						}
					}
					else break;
				}
			}
		}

		printf("Case %d: ", testcase++);
		int ans = path[end] + c;
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}