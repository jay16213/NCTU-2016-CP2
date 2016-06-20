#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int _power(int num,int n)
{
    long long int ans = 1;
    int i;
    for(i = 1;i <= n;i++)
        ans *= num;
    return ans;
}

int main()
{
    int a,b,i;
    char num[66];
    long long int dec = 0;
    int b_[66] = {0};
    char ans[66];

    while(1)
    {
        scanf("%d %d",&a,&b);
        fflush(stdin);
        if(a == 0 && b == 0) break;
        else
        {
            scanf("%s",num);
            //change to 10
            for(i = 0;i < strlen(num);i++)
            {
                if(num[i] >= 'A' && num[i] <= 'Z')
                {
                    int e = num[i]-'A'+10;
                    dec = dec + e*_power(a,strlen(num)-1-i);
                }
                else
                    dec = dec + (num[i]-'0')*_power(a,strlen(num)-1-i);
            }

            //change to b
            for(i = 0;dec > 0;i++)
            {
                b_[i] = dec%b;
                dec /= b;
            }
            int j;
            for(j = i-1;j >= 0;j--)
            {
                if(b_[j]  > 9)
                    ans[j] = 'A'+(b_[j]-10);
                else
                    ans[j] = b_[j]+'0';
                printf("%c",ans[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
