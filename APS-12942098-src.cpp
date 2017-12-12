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
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

bitset <10000005> bs;
int64 f[10000005];
int64 a[10000005];

void sieve(int64 n) {
    bs.set();
    bs.set(0,false);
    bs.set(1,false);
    for(int64 i=2;i*i<=n;i++)
        if(bs.test(i))
            for(int64 j=i*i;j<=n;j+=i) {
                bs.set(j,false);
                f[j] = i<f[j]?i:f[j];
            }
    for(int64 i=1;i<=n;i++)
        if(bs.test(i))
            f[i] = i;
}

int main() { //takeinput();
    int64 TC;
    cin>>TC;
    for(int64 i=1;i<=10000000;i++)f[i] = oo;
    sieve(10000000);
    a[0] = 0;
    a[1] = 0;
    for(int64 i=2;i<=10000000;i++)
        a[i] = a[i-1] + f[i];
    while(TC--) {
        int64 n;
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
