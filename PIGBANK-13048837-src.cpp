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

int main() { //takeinput();
    int TC;
    cin>>TC;

    while(TC--) {
        int a,b;
        cin>>a>>b;
        int weight = b-a;
        int n;
        cin>>n;
        int p[505],w[505];
        for(int i=1;i<=n;i++)
            cin>>p[i]>>w[i];
        //dp
        int dp[10005];
        memset(dp,oo,sizeof(dp));
        int foo = dp[0];
        dp[0] = 0;
        for(int i=1;i<=weight;i++)
            for(int j=1;j<=n;j++)
                if(i>=w[j])
                    dp[i] = min(dp[i],dp[i-w[j]]+p[j]);
        if(dp[weight]==foo) cout<<"This is impossible.\n";
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[weight]<<"."<<endl;
    }
    return 0;
}
