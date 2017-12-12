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

int main() { //takeinput();
    while(1) {
        int n1,n2;
        cin>>n1,n2;
        if(!n1)break;
        int a[10005],b[10005],sum1[10005],sum2[10005];
        for(int i=1;i<=n1;i++)
            cin>>a[i];
        cin>>n2;
        for(int i=1;i<=n2;i++)cin>>b[i];
        sum1[0]=0;
        for(int i=1;i<=n1;i++)
            sum1[i] = sum1[i-1]+a[i];
        sum2[0]=0;
        for(int i=1;i<=n2;i++)
            sum2[i] = sum2[i-1]+b[i];
        int ans = 0;
        int prev1 = 0,prev2 = 0;
        for(int i=1,j=1;i<=n1 && j<=n2;) {
            if(a[i]==b[j]) {
                ans = ans+max(sum1[i]-sum1[prev1],sum2[j]-sum2[prev2]);
                prev1 = i;
                prev2 = j;
                i++;
                j++;
                continue;
            }
            if(a[i]<b[j]){i++;continue;}
            if(a[i]>b[j]){j++;continue;}
        }
        cout<<ans+max(sum1[n1]-sum1[prev1],sum2[n2]-sum2[prev2])<<endl;
    }
    return 0;
}

