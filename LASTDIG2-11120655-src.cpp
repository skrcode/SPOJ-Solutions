#include <cstdlib>
#include<cstdio>
typedef long long int64;
#include<cstring>
//START
int main()
{    int TC;
   scanf("%d",&TC);
    while(TC--)
    {        int64 b;
        char str[1005];
        scanf("%s",str);
        scanf("%lld",&b);
        if(b==0){printf("1\n");continue;}
        int64 x = str[strlen(str)-1]-'0';
        int64 ans=x,i;
        for(i=2;i<=b;i++)
        {            ans=ans*x;
            if(ans%10==x)
                break;
        }
        b=b%(i-1);
        if(b==0)b=i-1;

        ans=1;
        for(int i=1;i<=b;i++)
        {            ans*=x;
        }

        printf("%lld\n",ans%10);
    }
    return EXIT_SUCCESS;
}
