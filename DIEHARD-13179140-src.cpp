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
int memo[1005][1005][5];

int dfs(int h,int a,int col) {
    if(h<=0 || a<=0)return -1;
    int ans = 0;
    if(memo[h][a][col]!=-1)return memo[h][a][col];
    if(col==0) {
        ans = max(dfs(h+3,a+2,1),max(dfs(h-5,a-10,2),dfs(h-20,a+5,3)));
    }
    if(col==1) {
        ans=max(dfs(h-5,a-10,2),dfs(h-20,a+5,3));
    }
    if(col==2) {
        ans=max(dfs(h+3,a+2,1),dfs(h-20,a+5,3));
    }
    if(col==3) {
        ans=max(dfs(h+3,a+2,1),dfs(h-5,a-10,2));
    }
    return memo[h][a][col] = 1+ans;
}

int main() {
    int TC;
    cin>>TC;

    while(TC--) {
        int h,a;
        cin>>h>>a;
        memset(memo,-1,sizeof(memo));
        cout<<dfs(h,a,0)<<endl;
    }
    return 0;
}
