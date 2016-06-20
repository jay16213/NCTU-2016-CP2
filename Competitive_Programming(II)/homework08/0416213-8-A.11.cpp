#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

void DFS_visit(int u, vector<vector<int>> &E, vector<bool> &discovered)
{
	for (int i = 0; i < E[u].size(); i++)
	{
		int v = E[u][i];//edge (u,v)
		if (!discovered[v])
		{
			discovered[v] = true;
			DFS_visit(v, E, discovered);
		}
	}
	return;
}

int main()
{
	int n;//the number of vertices in the graph
	while (cin >> n && n)
	{
		vector<vector<int>> E(n + 1, vector<int>());//1-base
		queue<int> Q;

		int start_v, vertex;
		while (cin >> start_v && start_v)
		{
			while (cin >> vertex && vertex)
				E[start_v].push_back(vertex);
		}

		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> start_v;
			Q.push(start_v);
		}

		while (!Q.empty())
		{
			int u = Q.front();//start point
			Q.pop();

			vector<bool> discovered(n + 1, false);
			DFS_visit(u, E, discovered);//visit each vertex that u can reach

			int ans = 0;//the numbers of vertices which u can't reach
			vector<int> v;//the vertices u can't reach
			for (int i = 1; i <= n;i++)
			{
				if (!discovered[i])
				{
					ans++;
					v.push_back(i);
				}
			}
			cout << ans;
			for (auto i : v)
			{
				cout << " " << i;
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}