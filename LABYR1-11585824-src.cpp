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
const double pi = 3.14159265358979323846264338327950;
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
int grid[1005][1005];
char str[1005];
const int dc[] = {0,0,-1,1};
const int dr[] = {1,-1,0,0};
int maxd=-1;
int posx,posy;
bool visited[1005][1005];

void dfs(int R,int C,int x,int y,int dist){
    if(x>R || y>C || y<1 || x<1) return;
    visited[x][y]=true;
    if(x<=R && y<=C && x>=1 && y>=1)
        if(dist>maxd){maxd = dist;posx=x;posy=y;}
    for(int i=0;i<4;i++)
        if(grid[x+dr[i]][y+dc[i]]==1 && visited[x+dr[i]][y+dc[i]]==false) dfs(R,C,x+dr[i],y+dc[i],dist+1);
}

int main(){//takeinput();
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int R,C;
        scanf("%d %d\n",&C,&R);
        memset(grid,0,sizeof(grid));
        for(int i=1;i<=R;i++){
            scanf("%s\n",str);
            for(int j=1;j<=C;j++) grid[i][j]=(str[j-1]=='.'?1:2);
        }
        bool f = true;
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(grid[i][j]==1){
                    memset(visited,false,sizeof(visited));
                    maxd=-1;
                    dfs(R,C,i,j,0);
                    f = false;
                    break;
                }
                if(!f) break;
            }
        }
        maxd=-1;
        memset(visited,false,sizeof(visited));
        dfs(R,C,posx,posy,0);
        printf("Maximum rope length is %d.\n",maxd!=-1?maxd:0);
    }
    return 0;
}

