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

bitset<1000005> bs;
vi primes;

void sieve(int n) {
    bs.set();
    bs.set(0,false);
    bs.set(1,false);
    for(int i=2;i*i<=n;i++)
        if(bs.test(i))
            for(int j=i*i;j<=n;j+=i)
                bs.set(j,false);
    for(int i=0;i<=n;i++)
        if(bs.test(i))
        primes.pb(i);
}

int main() {
    int TC;
    cin>>TC;
    sieve(1000000);
    while(TC--) {
        int n;
        cin>>n;
        int ans = -1;
        for(int i=0;i<primes.size() && n!=1;i++) {
            int cnt = 0;
            while(n%primes[i] == 0) {
                n/=primes[i];
                cnt++;
            }
            ans = max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
