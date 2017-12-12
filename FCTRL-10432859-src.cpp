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

int compute(int N)
{
    int ans=0;
    int i=10,j=1;

    while(i>=1)
    {
        ans=ans+N/pow(5,j++);
        i=N/pow(5,j);
    }

    return ans;
}


int main()
{
    int N,T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&N);

        printf("%d\n",compute(N));
    }

    return EXIT_SUCCESS;
}
