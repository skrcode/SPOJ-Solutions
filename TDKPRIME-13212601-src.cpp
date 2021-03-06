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

bitset <86029005> bs;
vi primes;

void sieve(int lim) {
    bs.reset();
    for(int x=1;x*x<=lim;x++)
        for(int y=1;y*y<=lim;y++) {
            int n = 4*x*x+y*y;
            if(n<=lim && (n%12==1 || n%12==5))bs.flip(n);
            n = 3*x*x+y*y;
            if(n<=lim && n%12==7)
                bs.flip(n);
            n = 3*x*x-y*y;
            if(x>y && n<=lim && n%12 == 11)
                bs.flip(n);
        }
    for(int n=5;n*n<=lim;n++)
        if(bs.test(n))
            for(int k=n*n;k<=lim;k+=(n*n))
                bs.set(k,false);
    primes.pb(2);
    primes.pb(3);
    primes.pb(5);
    for(int i=7;i<=lim;i+=2)
        if(bs.test(i))primes.pb(i);
}

int main() { //takeinput();
    int TC;
    scanf("%d",&TC);
    sieve(86029000);
    while(TC--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",primes[n-1]);
    }
    return 0;
}
