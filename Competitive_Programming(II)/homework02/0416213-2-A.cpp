#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;

int main()
{
	vector<int> rail;
	int n = 1;
	int train;
	while (cin >> n && n)
	{
		while (true)
		{
			queue<int> input;
			for (int i = 1; i <= n; i++)
			{
				cin >> train;
				if (train == 0)
				{
					cout << endl;
					cin >> n;
					if (n)
					{
						i = 0;
						continue;
					}
					else return 0;
				}
				else
                    input.push(train);
			}

			for (unsigned i = 1; i <= n; i++)
			{
				rail.push_back(i);
				while (rail.size() && rail.back() == input.front())
				{
					rail.pop_back();
					input.pop();
				}
			}

			if (rail.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			rail.clear();
		}
	}
	return 0;
}
