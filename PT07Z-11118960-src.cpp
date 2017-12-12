/*
   Author : SKRCODE
*/

#define DEBUG

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <cassert>

using namespace std;

const int oo = 2000000009;
const double eps = 1e-9;
#define mod 1000000007

#define debug printf("ERROR DETECTED...!!\n");
#ifdef DEBUG
    #define debug1(p)                cerr << #p << ": " << p << endl;
    #define debug2(p, q)             cerr << #p << ": " << p << " | " << #q << ": " << q << endl;
    #define debug3(p, q, r)          cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << endl;
    #define debug4(p, q, r, s)       cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << " | " << #s << ": " << s << endl;
    #define debug5(p, q, r, s, t)    cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << " | " << #s << ": " << s << " | " << #t << ": " << t << endl;
    #define debug6(p, q, r, s, t, u) cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << " | " << #s << ": " << s << " | " << #t << ": " << t << " | " << #u << ": " << u << endl;
#else
    #define debug1(p)
    #define debug2(p, q)
    #define debug3(p, q, r)
    #define debug4(p, q, r, s)
    #define debug5(p, q, r, s, t)
    #define debug6(p, q, r, s, t, u)
#endif
#define  takeinput() freopen("ip.txt","r",stdin);
typedef vector < int > vi;
typedef pair < int, int> ii;
typedef vector < ii > vii;
typedef set < int > si;
typedef map < string, int > msi;


#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define trvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define trmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define pb push_back
#define mp make_pair
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

#define dfs_white -1
#define dfs_black  1

vector <vii> AdjList(10005);
int dfs_num[10005];
int dist[10005];

void dfs(int u)
{
    dfs_num[u]=dfs_black;

    trvii(AdjList[u],v)
        if(dfs_num[v->first]==dfs_white)
        {
            dist[v->first]=dist[u]+1;
            dfs(v->first);
        }
}

int main()
{//takeinput();
    int n;

    scanf("%d",&n);

    memset(dfs_num,dfs_white,sizeof(dfs_num));
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        AdjList[u].pb(make_pair(v,0));
        AdjList[v].pb(make_pair(u,0));
    }

    int ans=-1;

    dfs(1);

    int j;
    int pos;
    for(j=1;j<=n;j++)
    {
        if(ans<dist[j])
        {
            ans=dist[j];
            pos=j;
        }
    }
    memset(dfs_num,dfs_white,sizeof(dfs_num));
    memset(dist,0,sizeof(dist));

    dfs(pos);

    ans=-1;
    for(j=1;j<=n;j++)
    {
        if(ans<dist[j])
        {
            ans=dist[j];
            pos=j;
        }
    }

    cout<<ans<<endl;
    return EXIT_SUCCESS;
}
