#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define INT_MAX 2147483647

bool Comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main()
{
	vector<pair<int, int> > turtle;
	
	int weight,strength;

	while (scanf("%d %d",&weight,&strength) != EOF)//input
		turtle.push_back(pair<int,int>(weight,strength-weight));

	sort(turtle.begin(),turtle.end(),Comp);//sort turtle by strength(increasing) 

	//the index is the number of turtles that can be stacked, c[index] is the minimum
	//total weight when the tower is stacked by index turtles
	vector<int> c(5608, INT_MAX);

	c[0] = 0;//there is 0 turtle ,so minimum total weight is 0

	int Size = turtle.size();//to avoid compute turtle.size() repeatly

	//choose turtles from top to bottom
	for (int i = 0; i < Size; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (turtle[i].second >= c[j])//if turtle[i] can be put in the bottom
				c[j + 1] = min(c[j+1],c[j] + turtle[i].first);//choose min total weight
		}
	}

	int ans;
	for (int i = Size - 1; i >= 0; i--)
	{
		if (c[i] != INT_MAX)
		{
			ans = i;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}