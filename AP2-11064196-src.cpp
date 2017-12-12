#include<cstdio>
#include<cstdlib>

typedef long long int64;
//START

int main()
{
    int TC;

    scanf("%d",&TC);

    while(TC--)
    {
        int64 n,a,d,tl,t,s;

        scanf("%lld %lld %lld",&t,&tl,&s);

        n=(2*s)/(t+tl);

        d = (tl-t)/(n-5);

        a = t - 2*d;

        printf("%lld\n",n);
        for(int64 i=1;i<=n;i++)
            printf("%lld ",a+(i-1)*d);
    }

    return EXIT_SUCCESS;
}
