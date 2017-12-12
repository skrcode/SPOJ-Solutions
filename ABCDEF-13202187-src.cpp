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
int arr1[1000005];
int arr2[1000005];
int cnt[1000005];
int main() {// takeinput();
    int n;
    scanf("%d",&n);
    int a[105];
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    map<int,int64> m;
    int ind1 = 0,ind2 = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                arr1[ind1++] = (a[i]*a[j]+a[k]);
    for(int i=1;i<=n;i++)
        if(a[i]!=0)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                arr2[ind2++] = (a[j]+a[k])*a[i];
    int64 ans = 0;
    sort(arr1,arr1+ind1);
    sort(arr2,arr2+ind2);
   // for(int i=0;i<ind1;i++)cout<<arr1[i]<<" ";cout<<endl;
   // for(int i=0;i<ind2;i++)cout<<arr2[i]<<" ";cout<<endl;
    for(int i=0,j=0;i<ind1 && j<ind2;) {
        if(arr1[i] == arr2[j]) {
            while(j<ind2 && arr1[i]==arr2[j]) {
                cnt[i]++;
                j++;
            }
            i++;
            continue;
        }
        if(arr1[i]<arr2[j]){i++;continue;}
        if(arr1[i]>arr2[j]){j++;continue;}
    }
    ans = cnt[0];
    for(int i=1;i<ind1;i++) {
        if(arr1[i] == arr1[i-1]) {
            cnt[i] = cnt[i-1];
        }
        ans+=cnt[i];
    }
    printf("%lld\n",ans);
    return 0;
}
