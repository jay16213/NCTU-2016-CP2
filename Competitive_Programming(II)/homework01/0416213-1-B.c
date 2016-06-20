#include<stdio.h>

int main()
{
    int T,i;
    int n,m,l,r;
    long long int num;
    long long int S[100001] = {0};
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i = 1;i <= n;i++)
        {
            scanf("%I64d",&num);
            S[i] = S[i-1]+num;
        }
        for(i = 0;i < m;i++)
        {
            scanf("%d %d",&l,&r);
            printf("%I64d\n",S[r]-S[l-1]);
        }
    }
    return 0;
}
