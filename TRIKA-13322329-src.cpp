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

int grid[30][30];
int memo[30][30];

int dfs(int row,int col,int n,int m) {
    if(row>n || row<1 || col>m || col <1)return oo;
    if(row == n && col == m)return grid[n][m];
    if(memo[row][col]!=-1)return memo[row][col];
    int ans = 0;
    ans = grid[row][col] + min(dfs(row+1,col,n,m) , dfs(row,col+1,n,m));
    return memo[row][col] = ans;
}


int main() { //takeinput();
    int n,m;
    cin>>n>>m;
    int sx,sy;
    cin>>sx>>sy;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>grid[i][j];
    memset(memo,-1,sizeof(memo));
    int mn = dfs(sx,sy,n,m);
    mn-=grid[sx][sy];
    mn = grid[sx][sy]-mn;
    if(mn<0) {
        cout<<"N\n";
        return 0;
    }
    cout<<"Y "<<mn<<endl;
    return 0;
}
