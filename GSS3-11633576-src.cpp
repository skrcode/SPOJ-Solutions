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

#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))


//START

struct qn{
    int sum,blsum,brsum,bsum;
}invalid;

vector <qn> seg_tree;

void init(int N){
    invalid.bsum = -oo;
    seg_tree.resize(lsegtree(N));
}

void build_seg_tree(int a[],int node,int b,int e){
    if(b==e){
        seg_tree[node].sum = a[b];
        seg_tree[node].blsum = a[b];
        seg_tree[node].brsum = a[b];
        seg_tree[node].bsum = a[b];
        return;
    }
    build_seg_tree(a,2*node,b,(b+e)/2);
    build_seg_tree(a,2*node+1,(b+e)/2+1,e);
    seg_tree[node].sum = seg_tree[2*node].sum + seg_tree[2*node+1].sum;
    seg_tree[node].blsum = max(seg_tree[2*node].blsum,seg_tree[2*node].sum+seg_tree[2*node+1].blsum);
    seg_tree[node].brsum = max(seg_tree[2*node+1].brsum,seg_tree[2*node+1].sum+seg_tree[2*node].brsum);
    seg_tree[node].bsum = max(seg_tree[2*node].bsum,max(seg_tree[2*node+1].bsum,seg_tree[2*node].brsum+seg_tree[2*node+1].blsum));
}

qn query(int a[],int node,int b,int e,int i,int j){
    if(b>j || e<i) { return invalid; }
    if(b>=i && e<=j) return seg_tree[node];

    qn p1 = query(a,2*node,b,(b+e)/2,i,j);
    qn p2 = query(a,2*node+1,(b+e)/2+1,e,i,j);

    if(p1.bsum==-oo) return p2;
    if(p2.bsum==-oo) return p1;

    qn temp;
    temp.bsum = max(p1.bsum,max(p2.bsum,p1.brsum+p2.blsum));
    temp.sum = p1.sum + p2.sum;
    temp.blsum = max(p1.blsum,p2.blsum+p1.sum);
    temp.brsum = max(p2.brsum,p2.sum+p1.brsum);
    return temp;
}

void update(int a[],int node,int b,int e,int i,int value){
    if(b==e){
        seg_tree[node].sum = value;
        seg_tree[node].blsum = value;
        seg_tree[node].brsum = value;
        seg_tree[node].bsum = value;
        return;
    }

    int mid = (b+e)/2;
    if(i<=mid) update(a,2*node,b,mid,i,value);
    else       update(a,2*node+1,mid+1,e,i,value);
    seg_tree[node].sum = seg_tree[2*node].sum + seg_tree[2*node+1].sum;
    seg_tree[node].blsum = max(seg_tree[2*node].blsum,seg_tree[2*node].sum+seg_tree[2*node+1].blsum);
    seg_tree[node].brsum = max(seg_tree[2*node+1].brsum,seg_tree[2*node+1].sum+seg_tree[2*node].brsum);
    seg_tree[node].bsum = max(seg_tree[2*node].bsum,max(seg_tree[2*node+1].bsum,seg_tree[2*node].brsum+seg_tree[2*node+1].blsum));
}


int main(){//takeinput();
    int N;
    int a[50005];
    int M;
    scanf("%d",&N);
    rep(i,1,N) scanf("%d",&a[i]);
    scanf("%d",&M);
    init(N);
    build_seg_tree(a,1,1,N);
    while(M--){
        int code,u,v;
        scanf("%d %d %d",&code,&u,&v);
        if(code==1)printf("%d\n",query(a,1,1,N,u,v).bsum);
        else update(a,1,1,N,u,v);
    }
    return 0;
}
