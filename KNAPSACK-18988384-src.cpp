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
#include <ctime>

using namespace std;

const int oo = int(2e9) + 9;
const double eps = 1e-9;
const double pi = 3.14159265358979323846264338327950;

#define debug printf("ERROR DETECTED...!!\n");
#define debug1(p)        cerr << #p << ": " << p << endl;
#define debug2(p, q)     cerr << #p << ": " << p << " | " << #q << ": " << q << endl;
#define debug3(p, q, r)  cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << endl;

#define  takeinput() freopen("ip","r",stdin);
#define  takeoutput() freopen("op","w",stdout);
#define  takein(c) freopen(c,"r",stdin)
#define  takeout(c) freopen(c,"w",stdout);

typedef vector < int > vi;
typedef pair < int, int> ii;
typedef vector < ii > vii;

#define trvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int64;
typedef unsigned long long uint64;
typedef double float64;

//START

int dp[2005][2005];

int main() { //takeinput()
    int N,S;
    cin>>S>>N;

    int val[2005],s[2005];

    for(int i=1;i<=N;i++) {
        scanf("%d %d",&s[i],&val[i]);
    }

    for(int i=1;i<=S;i++) {
        for(int j=1;j<=N;j++) {
            if(i>=s[j])
                dp[i][j] = max(dp[i-s[j]][j-1]+val[j],dp[i][j-1]);
            else
                dp[i][j] = dp[i][j-1];
            //debug3(i,j,dp[i][j])
        }
    }
    cout<<dp[S][N]<<endl;

    return 0;
}
