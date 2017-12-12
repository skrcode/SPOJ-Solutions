#include <cstdlib>
#include<cstdio>
typedef long long int64;
typedef double float64;
//START
int main()
{    int TC;
   scanf("%d",&TC);
    while(TC--)
    {        int64 a,b;
        scanf("%lld %lld",&a,&b);
        if(b==0){printf("1\n");continue;}
        int64 x = a%10;
        int64 ans=a,i;
        for(i=2;i<=b;i++)
        {            ans=ans*a;
            if(ans%10==x)
                break;
        }
        b=b%(i-1);
        if(b==0)b=i-1;

        ans=1;
        for(int i=1;i<=b;i++)
        {            ans*=a;
        }

        printf("%lld\n",ans%10);
    }
    return EXIT_SUCCESS;
}
