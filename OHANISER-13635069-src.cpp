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

const int64 mod = 1000000007;

int64 mul(int64 a,int64 b) {
    int64 ans = 1;
    while(b>0) {
        if(b%2)
            ans = (ans*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return ans;
}

int main() {
    int64 TC;
    cin>>TC;
    int64 ans = 1;
    int64 f[100005];
    f[1] = 1;
    for(int64 i=2;i<=100000;i++) {
        ans = ((2*ans)%mod + mul(2,i-2))%mod;
        f[i] = ans;
    }
    int64 kase = 1;
    while(TC--) {
        int64 n;
        cin>>n;
        cout<<"Case "<<kase++<<": ";
        cout<<f[n]<<endl;
    }
    return 0;
}
