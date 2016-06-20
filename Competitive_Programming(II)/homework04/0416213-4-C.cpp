#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

unsigned long long ans = 0;

void Merge(vector<int> &seq, int a_left, int a_right, int b_left, int b_right, unsigned long long &ans)
{
	int a_index = a_left, b_index = b_left,t_index = 0;
	vector<int> t(b_right-a_left+1);

	//merge seq[a_left,a_right] and seq[b_left,b_right]
	for (; a_index <= a_right && b_index <= b_right;t_index++)
	{
		if (seq[a_index] <= seq[b_index]) t[t_index] = seq[a_index++];
		else
		{
			t[t_index] = seq[b_index++];
			ans += (a_right-a_index+1);//a[a_index]~a[a_right] larger than b[b_index]
		}
	}

	for (; a_index <= a_right; a_index++, t_index++) t[t_index] = seq[a_index];
	for (; b_index <= b_right; b_index++, t_index++) t[t_index] = seq[b_index];

	for (int i = a_left; i <= b_right; i++) seq[i] = t[i-a_left];//copy t to seq
	return;
}

void MergeSort(vector<int> &seq,int left, int right,unsigned long long &ans)
{
	if (left < right)
	{
		int half = (right + left) / 2;
		MergeSort(seq,left, half,ans);
		MergeSort(seq,half + 1, right,ans);
		Merge(seq,left,half,half+1,right,ans);
	}
	return;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		int n,input;
		scanf("%d", &n);

		vector<int> seq(n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &input);
			seq[i] = input;
		}

		MergeSort(seq,0,n-1,ans);//mergesort seq and compute ans

		cout << ans << endl;
	}
	return 0;
}