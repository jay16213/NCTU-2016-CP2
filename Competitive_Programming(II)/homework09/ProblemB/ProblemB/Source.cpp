#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define MAX_INT 2147483647

class Mychar{
public:
	Mychar(){}
	Mychar(const char input){ c = input; }
	bool operator<=(Mychar& input){ return c <= input.c; }
	Mychar operator++(int dummy)
	{
		if (c == 'Z') c += 7;
		else c++;
		return *this;
	}
	char c;
};

bool isTown(const Mychar index){ return isupper(index.c); }

void getData(int &p,char &start,char &end)
{
	string input;
	getline(cin, input);
	for (int i = 0; i < input.size(); i++)
	{
		while (isdigit(input[i]))
			p = p * 10 + (input[i++] - '0');

		if (isalpha(input[i]))
		{
			if (start == '\0') start = input[i];
			else end = input[i];
		}
	}
}

void putWieght(int p, map<char, map<char, int> > point)
{
	for (Mychar i = 'A'; i <= Mychar('z'); i++)
	{
		for (Mychar j = 'A'; j <= Mychar('z'); j++)
		{
			if (point[i.c][j.c] == 1)
			{
				if (isTown(j)) point[i.c][j.c] = p / 20 + (p%20 != 0);
			}
		}
	}
}

int main()
{
	int n,testcase = 1;
	while (cin >> n && n != -1)
	{
		fflush(stdin);//clear input buffer
		map<char, map<char, int> > point;

		for (Mychar i = 'A'; i <= Mychar('z'); i++)
		{
			for (Mychar j = 'A'; j <= Mychar('z'); j++)
				point[i.c].insert(pair<char, int>(j.c, MAX_INT));
		}

		string input;
		char start = '\0', end = '\0';
		int p = 0;

		for (int i = 0; i < n; i++)
		{
			getline(cin,input);
			char fir = input[0];
			char sec = input[2];
			point[fir][sec] = 1;
			point[sec][fir] = 1;
		}
		getData(p,start,end);
		putWieght(p,point);

		point[start][start] = 0;
		map<char, map<char, int> > path;
		for (Mychar i = 'A'; i <= Mychar('z'); i++)
		{
			for (Mychar j = 'A'; j <= Mychar('z'); j++)
				path[i.c].insert(pair<char, int>(j.c, 0));
		}
		for (Mychar k = 'A'; k <= Mychar('z'); k++)
		{
			for (Mychar i = 'A'; i <= Mychar('z'); i++)
			{
				for (Mychar j = 'A'; j <= Mychar('z'); j++)
					path[i.c][j.c] = min(point[i.c][j.c],point[i.c][k.c] + point[k.c][j.c]);
			}
		}
		printf("Case %d: ",testcase++);
		int ans = point[start][end] + p;
		printf("%d\n",ans);
	}
	system("pause");
	return 0;
}