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
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

vi segtree(10000005);
int a[10000005];

void buildsegtree(int node,int b,int e) {
    if(b==e) {
        segtree[node] = a[b];
        return ;
    }
    buildsegtree(2*node,b,(b+e)/2);
    buildsegtree(2*node+1,(b+e)/2+1,e);
    segtree[node] = max(segtree[2*node],segtree[2*node+1]);
}

int query(int node,int b,int e,int i,int j) {
    if(b>=i && e<=j) return segtree[node];
    if(b>j || e<i) return -1;

    int p = query(2*node,b,(b+e)/2,i,j);
    int q = query(2*node+1,(b+e)/2+1,e,i,j);
    return max(p,q);
}

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    buildsegtree(1,1,n);
    int k;
    cin>>k;
    for(int i=1;i<=n-k+1;i++)
        cout<<query(1,1,n,i,i+k-1)<<" ";
    cout<<endl;
    return 0;
}
