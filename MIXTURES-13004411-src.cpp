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
int64 mn(int64 a,int64 b) {
    return a<b?a:b;
}
int main() { //takeinput();
    int64 n;
    while(cin>>n) {
        int64 a[105];
        for(int64 i=1;i<=n;i++) cin>>a[i];
        int64 smoke[105][105];
        int64 dp[105][105];
        memset(dp,oo,sizeof(dp));
        memset(smoke,oo,sizeof(smoke));
        for(int64 i=1;i<=n;i++) {
            smoke[i][i] = 0;
            dp[i][i] = a[i];
        }
        const int64 mod = 100;
        for(int64 i=n;i>=1;i--)
            for(int64 j=i+1;j<=n;j++)
                for(int64 k=i;k<=j-1;k++)
                    if(smoke[i][j] >= dp[i][k]*dp[k+1][j]) {
                        if(smoke[i][j] == dp[i][k]*dp[k+1][j]) dp[i][j] = mn(dp[i][j],(dp[i][k]%mod+dp[k+1][j]%mod)%mod);
                        else dp[i][j] = (dp[i][k]%mod+dp[k+1][j]%mod)%mod;
                        smoke[i][j] = mn(smoke[i][j],smoke[i][k]+smoke[k+1][j]+(dp[i][k]*dp[k+1][j]));
                    }
        /*for(int64 i=1;i<=n;i++) {
            for(int64 j=1;j<=n;j++)
                cout<<smoke[i][j]<<" ";
            cout<<endl;
        }*/
        cout<<smoke[1][n]<<endl;
    }
    return 0;
}
