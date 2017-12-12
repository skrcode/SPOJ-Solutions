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
int dp[5][1000005];

int nots(int a) {
    return a==1?2:1;
}

int main() {// takeinput();
    int a,b;
    cin>>a>>b;
    int TC;
    cin>>TC;
    memset(dp,oo,sizeof(dp));
    dp[1][0] = 2;
    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[2][0] = 1;
    dp[1][a] = 1;
    dp[2][b] = 2;
    for(int i=2;i<=1000000;i++) {
        dp[1][i] = dp[2][i-1];
        if(i>=a)dp[1][i] = min(dp[1][i],dp[2][i-a]);
        if(i>=b)dp[1][i] = min(dp[1][i],dp[2][i-b]);
        dp[2][i] = dp[1][i-1];
        if(i>=a)dp[2][i] = max(dp[2][i],dp[1][i-a]);
        if(i>=b)dp[2][i] = max(dp[2][i],dp[1][i-b]);
        //debug3(i,dp[1][i],dp[2][i]);
    }
    int n;
    while(cin>>n) {
        if(dp[1][n]==1)cout<<"A";
        else cout<<"B";
    }
    cout<<endl;
    return 0;
}
