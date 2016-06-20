#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

bool FindThreeSquares(int num, int ans[3], int occupied[223],int k,int limit)
{
	if (k == 3){
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		return true;
	}
	else{
		if(k == 2){
			int chk = ans[0] * ans[0] + ans[1] * ans[1];
			int i = sqrt(num-chk);
			if(chk+i*i == num)
			{
				printf("%d %d %d\n",ans[0],ans[1],i);
				return true;
			}
			else return false;
		}
		for (int i = k?ans[k-1]:0; i <= limit; i++)
		{
			if (occupied[i] == 3 || (occupied[i] == 2 && i == 0)) continue;
			else
			{
				occupied[i]++;
				ans[k] = i;
				if (FindThreeSquares(num, ans,occupied, k + 1,limit)) return true;
				occupied[i]--;
			}
		}
	}
	return false;
}

int main()
{
	int N, num;
	scanf("%d",&N);
	while (N--)
	{
		scanf("%d",&num);
		int Sqrt = sqrt(num);
		if(Sqrt*Sqrt == num)
		{
			printf("0 0 %d\n",Sqrt);
			continue;
		}
		int ans[3] = {0};
		int occupied[223] = {0};
		if (!FindThreeSquares(num, ans,occupied, 0,Sqrt))
			printf("-1\n");
	}
	return 0;
}