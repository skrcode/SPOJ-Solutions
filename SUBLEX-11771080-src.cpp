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
#include <climits>

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
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

int temp[100000],pos[100000],sa[100000],lcp[100000],sum[100000];
int gap,n;
char str[100000];

bool cmp(int a,int b){
    if(pos[a] != pos[b]) return pos[a] < pos[b];
    a+=gap;
    b+=gap;
    return (a<n && b<n)?pos[a]<pos[b]:a>b;
}

void buildsa(){
    n = strlen(str);
    for(int i=0;i<n;i++) sa[i] = i;
    for(int i=0;i<n;i++) pos[i] = str[i];
    for(gap = 1;;gap<<=1){
        sort(sa,sa+n,cmp);
        temp[0] = 0;
        for(int i=1;i<n;i++) temp[i] = temp[i-1] + cmp(sa[i-1],sa[i]);
        for(int i=0;i<n;i++) pos[sa[i]] = temp[i];
        if(temp[n-1] == n-1) break;
    }
}

void buildlcp(){
    int k = 0;
    for(int i = 0;i<n;i++)
        if(pos[i] != n-1){
            for(int j = sa[pos[i] + 1];str[i+k] == str[j+k];)
                k++;
            lcp[pos[i]] = k;
            if(k) k--;
        }
    lcp[n-1] = 0;
}

int main(){//takeinput()
    int Q;
    scanf("%s",str);
    scanf("%d",&Q);
    buildsa();
    buildlcp();//for(int64 i = 0;i<n;i++)printf("%s %d\n",str+sa[i],lcp[i]);
    sum[0] = n-sa[0];//printf("%d ",sum[0]);
    for(int i=1;i<n;i++) sum[i] = sum[i-1] + (n-sa[i]-lcp[i-1]);//printf("%d ",sum[i]);}printf("\n");
    while(Q--){
        int k;
        scanf("%d",&k);
        //Binary Search
        int lo = -1,hi = n-1,mid;
        while(lo<hi){
            mid = (lo+hi+1)/2;
            if(sum[mid] < k)lo = mid;
            else hi = mid-1;
        }
        int pos = lo + 1;//debug1(pos);
        int cnt = k - sum[pos-1];
        for(int j = 0;j<cnt+lcp[pos-1];j++)printf("%c",str[sa[pos]+j]);
        printf("\n");
    }
    return 0;
}
