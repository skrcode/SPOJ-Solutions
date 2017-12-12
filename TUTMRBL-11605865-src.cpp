/*
   Author : SKRCODE
*/

#define DEBUG

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
#include <ctime>
#include <string.h>
#include <cassert>

using namespace std;

const int oo = 2000000009;
const double eps = 1e-9;
const double pi = 3.14159265358979323846264338327950;
#define mod 1000000007

#define debug printf("ERROR DETECTED...!!\n");
#ifdef DEBUG
    #define debug1(p)                cerr << #p << ": " << p << endl;
    #define debug2(p, q)             cerr << #p << ": " << p << " | " << #q << ": " << q << endl;
    #define debug3(p, q, r)          cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << endl;
    #define debug4(p, q, r, s)       cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << " | " << #s << ": " << s << endl;
    #define debug5(p, q, r, s, t)    cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << " | " << #s << ": " << s << " | " << #t << ": " << t << endl;
    #define debug6(p, q, r, s, t, u) cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << " | " << #s << ": " << s << " | " << #t << ": " << t << " | " << #u << ": " << u << endl;
#else
    #define debug1(p)
    #define debug2(p, q)
    #define debug3(p, q, r)
    #define debug4(p, q, r, s)
    #define debug5(p, q, r, s, t)
    #define debug6(p, q, r, s, t, u)
#endif
#define  takeinput() freopen("ip.txt","r",stdin);
#define  takeoutput() freopen("op.txt","w",stdout);
typedef vector < int > vi;
typedef pair < int, int> ii;
typedef vector < ii > vii;
typedef set < int > si;
typedef map < string, int > msi;


#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define trvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define trmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define pb push_back
#define mp make_pair
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

bitset<10000005> bs;
vi primes;

void sieve(int n){
    bs.set();
    bs.set(0,false);
    bs.set(1,false);
    int root = sqrt(n);
    for(int i=2;i<=root;i++)
        if(bs.test(i))
            for(int j=i*i;j<=n;j+=i)
                bs.set(j,false);
    for(int i=0;i<=n;i++)
        if(bs.test(i))
            primes.pb(i);
}

bool isprime(int n){
    return bs.test(n);
}

int main(){
    int N;
    scanf("%d",&N);
    sieve(10000000/2);
    while(N!=0){
        printf("%d = ",N);
        int t = N;
        for(int i=0;i<primes.size() && primes[i]*primes[i]<=N;i++)
            if(N%primes[i]==0){
                while(N%primes[i]==0 && primes[i]*primes[i]<=N){
                    printf(" %d ",primes[i]);
                    N/=primes[i];
                    if(N>1) printf("*");
                    else     printf("\n");
                }
            }
        if(N>1) printf(" %d\n",N);
        int root = sqrt(t);
        int cnt = 0;
        for(int i=1;i<=root;i++)
            if(t%i==0) cnt++;
        printf("With %d marbles, %d different rectangles can be constructed.\n",t,cnt);
        scanf("%d",&N);
    }
    return 0;
}
