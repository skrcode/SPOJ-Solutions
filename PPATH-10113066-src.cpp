//SKRCODE
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<iomanip>
#include<deque>
#include<ctime>

using namespace std;

#define eps 0.00000001
#define maxsize 1000000000
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

typedef long long int64;
typedef long int32;

//beginning

bool isprime[10005];

bool sd(int a,int b)
{
    int count=0;

    while(a!=0)
    {
        if(a%10!=b%10)
            count++;
        a/=10;
        b/=10;
    }
    if(count==1)return true;
    else return false;

}

void sieve(int n)
{
    int i,root,k;

    for(i=0;i<=n;i++)
        isprime[i]=true;
    isprime[0]=false;
    isprime[1]=false;

    root=sqrt(n);

    for(i=2;i<=root;i++)
    {
        if(isprime[i])
            for(k=i*i;k<=n;k+=i)
                isprime[k]=false;
    }
}

int bfs(int beg,int end)
{
    int d[10000];
    int i,u;

    queue<int> Q;
    set<int> S;

    Q.push(beg);
    d[beg]=0;

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        S.insert(u);

        if(u==end)
            return d[u];

        for(i=1001;i<=9999;i++)
        {
            if(isprime[i])
                if(sd(i,u))
                    if(S.find(i)==S.end())
                    {
                        S.insert(i);
                        Q.push(i);
                        d[i]=d[u]+1;
                    }
        }
    }
}


int main()
{
    sieve(10000);

    int T,beg,end,N;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&beg,&end);

        printf("%d\n",bfs(beg,end));
    }

    return EXIT_SUCCESS;
}





