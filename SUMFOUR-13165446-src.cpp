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
vi a,b;
int grid[4005][100];
int main() { //takeinput();
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=4;j++)
            cin>>grid[i][j];
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a.pb(grid[i][1]+grid[j][2]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            b.pb(grid[i][3]+grid[j][4]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;
    //for(int i=0;i<b.size();i++)cout<<b[i]<<" ";cout<<endl;
    int sz1 = a.size();
    int sz2 = b.size();
    int ans = 0;
    for(int i=0;i<sz1;i++) {//debug1(a[i]);
        vector<int>::iterator l,u;
        l = lower_bound(b.begin(),b.end(),-a[i]);
        u = upper_bound(b.begin(),b.end(),-a[i]);
        ans+=(u-b.begin())-(l-b.begin());
    }
    cout<<ans<<endl;
    return 0;
}
