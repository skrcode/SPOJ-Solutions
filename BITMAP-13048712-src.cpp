/*
   Author : SKRCODE
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
int grid[200][200];
int dist[200][200];
int rc[5];
int color[200][200];

void bfs(int row,int col,int n,int m) {
    #define black 1
    #define white -1
    int sx = row,sy = col;
    queue < ii > q;
    q.push(mp(row,col));
    memset(color,white,sizeof(color));
    color[sx][sy] = black;
    while(!q.empty()) {
        ii u;
        u = q.front();
        q.pop();
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(color[u.first+rc[i]][u.second+rc[j]] == white && u.first+rc[i]<=n && u.first+rc[i]>=1 && u.second+rc[j]<=m && u.second+rc[j]>=1 && (rc[i]==0 || rc[j]==0) && dist[u.first+rc[i]][u.second+rc[j]]>dist[u.first][u.second]) {
                    dist[u.first+rc[i]][u.second+rc[j]] = min(dist[u.first][u.second] + 1,dist[u.first+rc[i]][u.second+rc[j]]);
                    q.push(mp(u.first+rc[i],u.second+rc[j]));
                    color[u.first+rc[i]][u.second+rc[j]] = black;
                }
    }
}

int main() { //takeinput();
    int TC;
    cin>>TC;
    rc[0] = -1;
    rc[1] = 0;
    rc[2] = 1;
    while(TC--) {
        int n,m;
        cin>>n>>m;
        memset(grid,0,sizeof(grid));
        memset(dist,oo,sizeof(dist));
        for(int i=1;i<=n;i++) {
            string str;
            cin>>str;
            for(int j=1;j<=m;j++) {
                grid[i][j] = str[j-1]-'0';
                if(grid[i][j])dist[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(grid[i][j])bfs(i,j,n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cout<<dist[i][j]<<(j==m?'\n':' ');
    }
    return 0;
}
