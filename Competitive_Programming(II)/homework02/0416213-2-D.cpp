#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

void InsertToPassword(set<string> *password,string sorce,char add)
{
    for(string::iterator it = sorce.begin();it != sorce.end()+1;it++)
    {
        it = sorce.insert(it,add);
        password->insert(sorce);
        sorce.erase(it);
    }
}

int main()
{
	int N, R, input, sum = 0;
	char add;
	string psd;
	set<string> password;

	while (cin >> N >> R)
	{
		sum = 0;
		for (int i = 1; i <= N - 1; i++)
		{
			scanf("%1d", &input);
			psd.push_back(input+'0');
			sum += input;
		}

        //count the sum of input while the sum is not 1 digit
        int tmp = sum;
		while (tmp >= 10)
		{
			sum = 0;
			for (; tmp > 0; tmp /= 10)
				sum = sum + tmp % 10;
			tmp = sum;
		}

        if(R >= sum)
        {
            add = R-sum+'0';//add is the number we want.
            InsertToPassword(&password,psd,add);

            if(R == sum)
                InsertToPassword(&password,psd,'9');
        }
        else
        {
            add = (10+(R-1))-sum+'0';
            InsertToPassword(&password,psd,add);
        }

		for (set<string>::iterator sit = ++password.begin(); sit != --password.end(); sit++)
			cout << *sit << endl;

		psd.clear();
		password.clear();
    }
	return 0;
}
