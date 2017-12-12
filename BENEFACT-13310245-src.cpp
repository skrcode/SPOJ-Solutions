/*
   Author : skrcode
*/

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
#include <string.h>
#include <cassert>
#include <climits>

using namespace std;

const int oo = int(2e9) + 9;
const double eps = 1e-9;
const double pi = 3.14159265358979323846264338327950;

#define debug printf("ERROR DETECTED...!!\n");
#define debug1(p)        cerr << #p << ": " << p << endl;
#define debug2(p, q)     cerr << #p << ": " << p << " | " << #q << ": " << q << endl;
#define debug3(p, q, r)  cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << endl;

#define  takeinput() freopen("ip.txt","r",stdin);
#define  takeoutput() freopen("op.txt","w",stdout);

typedef vector < int > vi;
typedef pair < int, int> ii;
typedef vector < ii > vii;

#define trvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define pb push_back
#define mp make_pair


typedef long long int64;
typedef double float64;

//START

#define dfs_white -1
#define dfs_black  1

int dfs_num[50005];
vector <vii> AdjList(50005);
int dist[50005];
int dfs(int u) {
    dfs_num[u] = dfs_black;
    int ans = 0;
    trvii(AdjList[u],v)
        if(dfs_num[v->first] == dfs_white)
            ans = max(ans,dfs(v->first) + v->second);
    return ans;
}

void dfs1(int u) {
    dfs_num[u] = dfs_black;
    int ans = 0;
    trvii(AdjList[u],v)
        if(dfs_num[v->first] == dfs_white) {
            dist[v->first] = dist[u] + v->second;
            dfs1(v->first);
        }
}

int main() {//takeinput()
    int TC;
    cin>>TC;

    while(TC--) {
        int n;
        cin>>n;
        for(int i=1;i<n;i++) {
            int u,v,f;
            cin>>u>>v>>f;
            AdjList[u].pb(mp(v,f));
            AdjList[v].pb(mp(u,f));
        }
        memset(dfs_num,dfs_white,sizeof(dfs_num));
        memset(dist,0,sizeof(dist));
        dfs1(1);
        int mx = -1;
        int pos;
        for(int i=1;i<=n;i++)
            if(mx<dist[i]) {
                mx = dist[i];
                pos=  i;
            }
        memset(dfs_num,dfs_white,sizeof(dfs_num));
        cout<<dfs(pos)<<endl;
        for(int i=0;i<=50003;i++)AdjList[i].clear();
    }
    return 0;
}
