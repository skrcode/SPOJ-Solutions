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

int64 grid[25][25];
int64 memo[(1<<22)+5];

int64 dp(int64 mask,int64 id,int64 n) {
    if(id>n)return 1;

    if(memo[mask]!=-1){return memo[mask];}
    int64 ans = 0;
    for(int64 i=1;i<=n;i++)
        if(grid[i][id])
            if(!(mask&(1<<i)))
                ans+=dp(mask|(1<<i),id+1,n);
    return memo[mask] = ans;
}

int main() {// takeinput();
    int TC;
    scanf("%d",&TC);

    while(TC--) {
        int64 n;
        scanf("%lld",&n);
        for(int64 i=1;i<=n;i++)
            for(int64 j=1;j<=n;j++)
                scanf("%ld",&grid[i][j]);
        for(int i=0;i<=(1<<(n+1));i++)
            //for(int j=1;j<=n;j++)
                memo[i] = -1;
        printf("%lld\n",dp(0,1,n));
    }
    return 0;
}
