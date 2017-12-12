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
const int64 mod = 1000000007;

void mul(int64 res[5][5]) {
    int64 a = res[0][0],b = res[0][1], c = res[1][0] , d = res[1][1];
    res[0][0] = ((a%mod)+(b%mod))%mod;
    res[0][1] = a;
    res[1][0] = ((c%mod)+(d%mod))%mod;
    res[1][1] = c;
}

void sq(int64 res[5][5]) {
    int64 a = res[0][0],b = res[0][1], c = res[1][0] , d = res[1][1];
    res[0][0] = ((((a%mod)*(a%mod))%mod)+(((b%mod)*(c%mod))%mod))%mod;
    res[0][1] = ((((a%mod)*(b%mod))%mod)+(((b%mod)*(d%mod))%mod))%mod;
    res[1][0] = ((((a%mod)*(c%mod))%mod)+(((c%mod)*(d%mod))%mod))%mod;
    res[1][1] = ((((c%mod)*(b%mod))%mod)+(((d%mod)*(d%mod))%mod))%mod;
}

void fastexpo(int64 res[5][5],int64 n) {
    if(n==1)return;
    if(n%2) {
        fastexpo(res,n-1);
        mul(res);
        return ;
    }
    fastexpo(res,n/2);
    sq(res);
}

int64 fib(int64 n) {
    if(!n)return 1;
    int64 res[5][5];
    res[0][0] = 1;
    res[0][1] = 1;
    res[1][0] = 1;
    res[1][1] = 0;
    fastexpo(res,n);
    return res[0][0];
}

int main() {
    int TC;
    cin>>TC;

    while(TC--) {
        int64 a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        int64 x = fib(b+1);
        int64 y = fib(a);
        if(x<y) {
            cout<<(x-y+mod)<<endl;
        }
        else cout<<x-y<<endl;
    }
    return 0;
}
