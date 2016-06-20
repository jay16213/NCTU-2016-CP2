#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<int,int> work;//first is the priority of work,second is the number of work
	map<int, int>::iterator it;

	int input;
	int i = 0;
	while (scanf("%d",&input) && input)
	{
		if (input == -1)
		{
		    if(work.size())
            {
                if (i && input < 0) printf(" ");//output-format control
                i = 1;

                it = work.begin();
                printf("%d", it->first);

                it->second--;
                if (it->second == 0)
                    work.erase(it);
            }
		}
		else if (input == -2)
		{
		    if(work.size())
            {
                if (i && input < 0) printf(" ");//output-format control
                i = 1;

                it = --work.end();
                printf("%d", it->first);

                it->second--;
                if (it->second == 0)
                    work.erase(it);
            }
		}
		else
        {
            if (work.find(input) != work.end())
                work[input]++;
            else
                work.insert(pair<int, int>(input, 1));
        }
	}
	printf("\n");
	return 0;
}
