#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

bool SearchAns(vector<long long int> road, int n, int w, int m,int x)
{
	for (int i = 0; i < n; i++)
	{
		if (road[i] <= 0) continue;

		int y = 0;	//y is the number of days that road[i] requires to down to <= 0
		do
		{
			road[i] -= x;
			y++;
		} while (road[i] > 0);
		m -= y;
		
		long long int Push = y*x;	//the total height being pushed in [i,i+w]
		for (int j = i + 1; (j < n) && (j < i + w); j++)
			road[j] -= Push;
	}
	return m >= 0;	//if m >= 0, then x is possible to be the answer => return true
}

int main()
{
	int T;
	int n,w,m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &n, &w, &m);

		vector<long long int> road(n);
		int input;
		int Max = 0;//the Max height of road

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &input);
			road[i] = input;
			if (input > Max) Max = input;
		}

		int ans = -1;
		int L = 1, R = Max + 1;

		while ((R - L) > 0)
		{
			int x = (L + R) / 2;	//binary search
			if (SearchAns(road, n, w, m, x))	//if x is possible to be the answer,than ans = x and set R = x
			{
				ans = x;
				R = x;
			}
			else L = x + 1;	//otherwise,set L = x+1
		}
		printf("%d\n", ans);
	}
	return 0;
}