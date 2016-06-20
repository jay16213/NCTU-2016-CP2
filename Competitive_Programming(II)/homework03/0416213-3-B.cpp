#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

bool is_Same(int index,vector<int> source, vector<int> same)
{
	for (int k = 0; k < same.size(); k++)
		if (source[index] == same[k]) return true;

	return false;
}

void Method_of_Sums(int t, vector<int> source, vector<int> ans, bool &haveAns, int last)
{
	static int occupied[12] = {0};
	if (t == 0)
	{
		for (int i = 0; i < ans.size();)
		{
			cout << ans[i];
			if (++i != ans.size()) cout << "+";
		}
		cout << endl;
		haveAns = true;
		return;
	}

	vector<int> same;
	for (int i = last; i < source.size();i++)
	{
		if (occupied[i] > 0) continue;
		else if (t - source[i] < 0) continue;
		else if (is_Same(i,source,same)) continue;//if we have enumed the number this recursion depth,continue

		same.push_back(source[i]);//record the source number which we have enumed this recursion depth
		occupied[i]++;
		t -= source[i];
		ans.push_back(source[i]);

		/*because we don't want to enum the same combinations,such as (3,1) & (1,3),so we
		record i(last) to avoid this situation*/
		Method_of_Sums(t, source, ans, haveAns, i);
		occupied[i]--;
		t += source[i];
		ans.pop_back();
	}

	return;
}
int main()
{
	int t, n;

	while ((cin >> t >> n) && n)
	{
		vector<int> source(n);
		vector<int> ans;
		bool haveAns = false;//check if this test case has any answers
		for (int i = 0; i < n; i++)//get the source number
			cin >> source[i];

		cout << "Sums of " << t << ":" << endl;
		Method_of_Sums(t, source, ans, haveAns, 0);
		if (!haveAns) cout << "NONE" << endl;
		ans.clear();
	}
	return 0;
}