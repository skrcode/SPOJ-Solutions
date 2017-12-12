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
#define  takeoutput() freopen("op.txt","w",stdout);
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

#define white -1
#define red 0
#define blue 1

vector<vii> AdjList(2005);
bool visited[2005];

int bfs(int s){
    queue<int> q;
    map<int,int> dist;
    int color[2005];
    memset(color,white,sizeof(color));
    q.push(s);
    dist[s] = 0;
    color[s] = red;

    while(!q.empty()){
        int u = q.front(); q.pop();
        visited[u]=true;
        trvii(AdjList[u],v){
            if(color[v->first]==color[u]) return 0;
                else color[v->first]=color[u]==blue?red:blue;
            if(dist.find(v->first)==dist.end()){
                dist[v->first]=dist[u]+1;
                q.push(v->first);
            }
        }
    }

    return 1;
}

int main(){//takeinput();
    int TC,i=1;
    int color[2005];
    scanf("%d",&TC);
    while(TC--){
        printf("Scenario #%d:\n",i++);
        int N,M;
        scanf("%d %d",&N,&M);
        memset(visited,false,sizeof(visited));
        int u,v;
        while(M--){
            scanf("%d %d",&u,&v);
            AdjList[u].pb(mp(v,0));
            AdjList[v].pb(mp(u,0));
        }
        int ans = bfs(u);

        if(!ans) printf("Suspicious bugs found!\n");
        else    printf("No suspicious bugs found!\n");
        rep(i,0,2004) AdjList[i].clear();
    }
    return 0;
}

