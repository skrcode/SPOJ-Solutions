/*
   ##################
  # Author : SKRCODE #
   ##################
*/
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
#define MOD 1000000007
#define maxsize 1000000000
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int64;
typedef long int32;

//START

int rev(int x)
{
    int d;
    int numrev=0;

    while(x>0)
    {
        d=x%10;
        numrev=numrev*10+d;
        x/=10;
    }

    return numrev;
}

int main()
{
    int T;
    int x,y;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&x,&y);

        x=rev(x);
        y=rev(y);
        printf("%d\n",rev(x+y));
    }


    return EXIT_SUCCESS;
}






