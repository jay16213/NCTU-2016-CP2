#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

unsigned long long BFS(vector<int> population, vector<vector<int>> &road, vector<bool> &finished, int start, int n)
{
	queue<int> city;
	city.push(start);
	finished[start] = true;
	unsigned long long sum = population[start];

	while (!city.empty())
	{
		int u = city.front();//point u
		city.pop();

		for (auto i : road[u])
		{
			int v = i;//edge (u,v)
			if (!finished[v])
			{
				city.push(v);
				finished[v] = true;
				sum += population[v];
			}
		}
	}

	return sum;
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		int n, m;
		unsigned long long max_market = 0;
		scanf("%d %d", &n, &m);

		vector<int> population(n + 1);
		vector<vector<int>> road(n + 1, vector<int>());

		for (int i = 1; i <= n; i++)
			cin >> population[i];

		for (int i = 0; i < m; i++)
		{
			int b, c;
			scanf("%d %d", &b, &c);
			road[b].push_back(c);
			road[c].push_back(b);
		}

		vector<bool> finished(n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			if (finished[i]) continue;

			//compute the population of the same market
			unsigned long long market = BFS(population, road, finished, i, n);
			if (market > max_market) max_market = market;
		}

		cout << max_market << endl;
	}
	return 0;
}