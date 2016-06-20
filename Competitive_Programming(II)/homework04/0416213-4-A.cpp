#include<iostream>
#include<map>
#include<cstdlib>
#define remain 100000007
using namespace std;

map<int,long long int> a;

long long int ComputeAns(int N)//return 3^N
{
	map<int, long long int>::iterator it = a.find(N);
	if (it != a.end()) return it->second;//if 3^N has been computed,return

	if (N % 2 == 0)//if 3^N has not computed yet,compute it and insert to a
	{	
		long long int tmp = ((ComputeAns(N / 2) % remain)*(ComputeAns(N / 2) % remain)) % remain;
		a.insert(pair<int, long long int>(N,tmp));
		return tmp;
	}
	else
	{
		long long int tmp = (3 * (((ComputeAns(N / 2) % remain) * (ComputeAns(N / 2) % remain)) % remain)) % remain;
		a.insert(pair<int, long long int>(N, tmp));
		return tmp;
	}
}

int main()
{
	//a is a map,whose key is n and value is 3^n
	//By using a,we can get 3^n quickly without computing it repeatily
	a.insert(pair<int, long long int>(0, 1));
	a.insert(pair<int, long long int>(1, 3));

	int T,N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << ComputeAns(N)-1 << endl;//After simplifying,we know that the answer is 3^N-1
	}
	return 0;
}