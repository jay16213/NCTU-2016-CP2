#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct segment
{
	int Start;
	int End;
};

bool Comp(segment a, segment b) { return a.Start < b.Start; }

int main()
{
	int T, M;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		if (t) printf("\n");
		vector<segment> line;
		vector<segment> ans;
		scanf("%d", &M);
		segment input;
		while (scanf("%d %d", &input.Start, &input.End) && (input.Start != 0 || input.End != 0))
			line.push_back(input);

		sort(line.begin(), line.end(), Comp);

		int Size = line.size();
		int left = 0, right = 0;//the bound which is covered from left to right now
		for (int i = 0; i < Size; i++)
		{
			int Best_choise = -1;//choose the max distanse(line[i].Start,line[i].End)
			for (; i < Size && line[i].Start <= left; i++)
			{
				if (line[i].End > right)//if End is cover the right bound or not
				{
					right = line[i].End;
					Best_choise = i;//because we have sorted line, line[i] must be the best choise so far
				}
			}
			if (Best_choise != -1)
			{
				ans.push_back(line[Best_choise]);
				if (right >= M) break;
				left = right;
				i--;
			}
			else break;
		}

		if (right < M)//no answer
		{
			printf("0\n");
			continue;
		}

		int ans_Size = ans.size();
		printf("%d\n", ans_Size);
		for (int i = 0; i < ans_Size; i++) printf("%d %d\n", ans[i].Start, ans[i].End);
	}
	return 0;
}