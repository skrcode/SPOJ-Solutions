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

int main() {// takeinput();
    int TC;
    scanf("%d",&TC);
    int kase = 1;
    while(TC--) {
        printf("Case %d:\n",kase++);
        int n;
        scanf("%d",&n);
        int q;
        scanf("%d",&q);
        int a[100005];
        int cnt[100005];
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        cnt[0] = 0;
        cnt[1] = 1;
        for(int i=2;i<=n;i++) {
            if(a[i] == a[i-1])cnt[i] = cnt[i-1];
            else cnt[i] = cnt[i-1]+1;
        }
        while(q--) {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%d\n",cnt[v]-cnt[u]+1);
        }
    }
    return 0;
}
