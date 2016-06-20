#include<bits/stdc++.h>

using namespace std;

int main()
{
    const int buf_size = 100500;
    static char buf[buf_size];

    int num = 0;
    long long int ans = 0;


    while(fgets(buf,sizeof(buf),stdin) != NULL)
    {
        ans = 0;
        strtok(buf,"\n");
        for(char *ptr = strtok(buf," ");ptr != NULL;ptr = strtok(NULL," "))
        {
            num = 0;

            for(int i = 0;i < strlen(ptr);i++)
                num = (num*10)+(*(ptr+i)-'0');

            ans += num;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

