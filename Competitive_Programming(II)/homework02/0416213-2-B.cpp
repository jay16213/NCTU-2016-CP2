#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> paper;
        if(n == 0) break;

        for(int i = 1;i <= n;i++)
        {
            int tmp;
            cin >> tmp;
            paper.push_back(tmp);
        }
        sort(paper.begin(),paper.end());

        int sum = 0;
        do{
            sum = 0;
            for(int i = 0;i < n-1;i++)
            {
                sum += paper[i];
            }

            if(sum >= paper[n-1])
            {
                cout << n << endl;
                break;
            }
            else n--;
        }while(n);

        if(n == 0) cout << n << endl;
    }
    return 0;
}
