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

void sieve(int n)
{
    bs.set();
    bs.set(0,false);
    bs.set(1,false);

    int root = sqrt(n);
    for(int i= 2;i<=root;i++)
    {
        if(bs.test(i))
        {
            for(int j=i*i;j<=n;j+=i)
                bs.set(j,false);
        }
    }

    for(int i=0;i<=n;i++)
        if(bs.test(i))
            primes.pb(i);
}

vi findpf(int n)
{
    int root = sqrt(n);

    int pf=0;
    vi primefactors;

    while(n!=1 && primes[pf]<=root)
    {
        if(n%primes[pf]==0)
        {
            while(n%primes[pf]==0)
                n/=primes[pf];
            primefactors.pb(primes[pf]);
        }
        pf++;
    }

    if(n!=1)primefactors.pb(n);

    return primefactors;
}

int main()
{
    //takeinput();
    int TC;
    vi primefactors;
    sieve(1000005);
    scanf("%d",&TC);

    while(TC--)
    {
        int n,phi;


        scanf("%d",&n);

        //Compute euler totient

        phi=n;

        primefactors=findpf(n);

        for(int i=0;i<primefactors.size();i++)
        {
            phi=phi-phi/primefactors[i];
        }
        cout<<phi<<endl;

        primefactors.clear();
    }

    return EXIT_SUCCESS;
}
