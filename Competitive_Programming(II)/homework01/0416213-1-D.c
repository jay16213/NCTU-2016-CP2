#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    long long int x,y;
    char command[4];
    long long int d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d %I64d",&x,&y);
        fflush(stdin);
        while(scanf("%s",&command) != 0)
        {
            if(command[0] == 'E') break;
            else
            {
                scanf("%I64d",&d);

                if(command[0] == 'L') x -= d;
                if(command[0] == 'U') y += d;
                if(command[0] == 'R') x += d;
                if(command[0] == 'D') y -= d;
            }
        }
        printf("%I64d %I64d\n",x,y);
        fflush(stdin);
    }
    return 0;
}
