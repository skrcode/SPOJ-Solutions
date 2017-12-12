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

vector < pair <int64 ,int64 > > segtree(8*100005);

void build(int64  a[],int64  node,int64  b,int64  e) {
    if(b==e) {
        segtree[node].first = a[b];
        segtree[node].second = -1;
        return;
    }
    build(a,2*node,b,(b+e)/2);
    build(a,2*node+1,(b+e)/2+1,e);
    if(e==b+1) {
        if(segtree[2*node].first>segtree[2*node+1].first) {
            segtree[node].first = segtree[2*node].first;
            segtree[node].second = segtree[2*node+1].first;
        }
        else {
            segtree[node].first = segtree[2*node+1].first;
            segtree[node].second = segtree[2*node].first;
        }
        return;
    }
    if(segtree[2*node].first>segtree[2*node+1].first) {
        segtree[node].first = segtree[2*node].first;
        if(segtree[2*node].second>segtree[2*node+1].first)
            segtree[node].second = segtree[2*node].second;
        else
            segtree[node].second = segtree[2*node+1].first;
    }
    else {
        segtree[node].first = segtree[2*node+1].first;
        if(segtree[2*node+1].second>segtree[2*node].first)
            segtree[node].second = segtree[2*node+1].second;
        else
            segtree[node].second = segtree[2*node].first;
    }
}

pair<int64 ,int64 > query(int64  a[],int64  node,int64  b,int64  e,int64  i,int64  j) {
    if(b>j || e<i)return mp(-1,-1);
    if(b>=i && e<=j)
        return mp(segtree[node].first,segtree[node].second);
    ii x = query(a,2*node,b,(b+e)/2,i,j);
    ii y = query(a,2*node+1,(b+e)/2+1,e,i,j);
    ii z;
    if(x.first == -1)return y;
    if(y.first == -1)return x;
    if(x.first>y.first) {
        z.first = x.first;
        if(x.second>y.first)
            z.second = x.second;
        else
            z.second = y.first;
    }
    else {
        z.first = y.first;
        if(y.second>x.first)
            z.second = y.second;
        else
            z.second = x.first;
    }
    return z;
}

void update(int64  a[],int64  node,int64  b,int64  e,int64  pos,int64  val) {//debug2(b,e);
    if(b==e) {
        segtree[node].first = val;
        segtree[node].second = -1;
        return;
    }

    if(pos<=(b+e)/2)update(a,2*node,b,(b+e)/2,pos,val);
    else update(a,2*node+1,(b+e)/2+1,e,pos,val);
    if(e==b+1) {
        if(segtree[2*node].first>segtree[2*node+1].first) {
            segtree[node].first = segtree[2*node].first;
            segtree[node].second = segtree[2*node+1].first;
        }
        else {
            segtree[node].first = segtree[2*node+1].first;
            segtree[node].second = segtree[2*node].first;
        }
        return;
    }
    if(segtree[2*node].first>segtree[2*node+1].first) {
        segtree[node].first = segtree[2*node].first;
        if(segtree[2*node].second>segtree[2*node+1].first)
            segtree[node].second = segtree[2*node].second;
        else
            segtree[node].second = segtree[2*node+1].first;
    }
    else {
        segtree[node].first = segtree[2*node+1].first;
        if(segtree[2*node+1].second>segtree[2*node].first)
            segtree[node].second = segtree[2*node+1].second;
        else
            segtree[node].second = segtree[2*node].first;
    }
}

int main() {//takeinput();
    int64  n;
    cin>>n;
    int64  a[200005];
    for(int64  i=1;i<=n;i++) cin>>a[i];
    build(a,1,1,n);
    int64  q;
    cin>>q;

    while(q--) {
        char code;
        cin>>code;

        if(code == 'Q') {
            int64  u,v;
            cin>>u>>v;
            ii res;
            res = query(a,1,1,n,u,v);
            cout<<res.first+res.second<<endl;

        }
        else {
            int64  u,v;
            cin>>u>>v;
            update(a,1,1,n,u,v);
        }
    }
    return 0;
}
