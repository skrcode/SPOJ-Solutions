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

bool check(float64 mid,float64 a[10005],int n,int m) {
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        int x = int(a[i]/mid);
        cnt+=x;
    }
    if(cnt>=m+1)return true;
    return false;
}

int main() { //takeinput();
    int TC;
    scanf("%d",&TC);

    while(TC--) {
        int n,m;
        scanf("%d %d",&n,&m);
        float64 a[10005];
        for(int i=1;i<=n;i++) {
            scanf("%lf",&a[i]);
            a[i] = pi*a[i]*a[i];
        }
        sort(a+1,a+n+1);
        float64 lo = 0.0001;
        float64 hi = a[n];
        float64 mid;
        float64 ans = float64(-1);

        while(hi-lo>=1e-6) {//debug3(lo,hi,lo-hi);
            mid = lo + (hi-lo)/2;
            if(check(mid,a,n,m)) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        printf("%.4lf\n",lo);
    }
    return 0;
}


