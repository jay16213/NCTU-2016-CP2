#include<stdio.h>

int main()
{
    int t;
    int p;
    scanf("%d",&t);
    while(t--)
    {
        int judge = 1;
        scanf("%d",&p);

        if(p <= 1)
            printf("no\n");
        else
        {
            int i;
            for(i = 2;i*i <= p;i++)
            {
                if(p%i == 0)
                {
                    judge = 0;
                    break;
                }
            }
            if(judge) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
