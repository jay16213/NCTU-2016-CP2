#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	while(n--)
	{
		cin >> m;
		vector<int> coin(m);
		int sum = 0;
		int c[100000] = {0};

		for (int i = 0; i < m; i++)
		{
			int input;
			cin >> input;
			coin[i] = input;
			sum += input;
		}

		int ave = sum / 2;
		for (int i = 0; i < m; i++)
		{
			for (int j = ave; j >= coin[i]; j--)
				c[j] = max(c[j],c[j-coin[i]] + coin[i]);
		}

		cout << sum-2*c[ave] << endl;
	}
	return 0;
}
