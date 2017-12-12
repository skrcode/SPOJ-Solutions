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

int bfs(int a,int b,int c) {
    queue<ii> q;
    q.push(mp(0,0));
    map<ii,int> dist;
    dist[mp(0,0)] = 1;
    while(!q.empty()) {
        ii x = q.front(); q.pop();//debug2(x.first,x.second);
        if(x.first==c || x.second==c)return dist[x]-1;
        ii one = mp(x.first,0);
        ii two = mp(0,x.second);
        int capc = b-x.second;
        ii three = mp(x.first-capc,b);
        capc = a-x.first;
        ii four = mp(a,x.second-capc);
        ii five = mp(a,x.second);
        ii six = mp(x.first,b);
        ii seven = mp(0,x.first+x.second);
        ii eight = mp(x.first+x.second,0);
        if(!(one.first>a || one.first<0 || one.second>b || one.second<0) && !dist[one]){q.push(one);dist[one] = dist[x]+1;}
        if(!(two.first>a || two.first<0 || two.second>b || two.second<0) && !dist[two]){q.push(two);dist[two] = dist[x]+1;}
        if(!(three.first>a || three.first<0 || three.second>b || three.second<0) && !dist[three]){q.push(three);dist[three] = dist[x]+1;}
        if(!(four.first>a || four.first<0 || four.second>b || four.second<0) && !dist[four]){q.push(four);dist[four] = dist[x]+1;}
        if(!(five.first>a || five.first<0 || five.second>b || five.second<0) && !dist[five]){q.push(five);dist[five] = dist[x]+1;}
        if(!(six.first>a || six.first<0 || six.second>b || six.second<0) && !dist[six]){q.push(six);dist[six] = dist[x]+1;}
        if(!(seven.first>a || seven.first<0 || seven.second>b || seven.second<0) && !dist[seven]){q.push(seven);dist[seven] = dist[x]+1;}
        if(!(eight.first>a || eight.first<0 || eight.second>b || eight.second<0) && !dist[eight]){q.push(eight);dist[eight] = dist[x]+1;}
    }
    return -1;
}
int main() { //takeinput();
    int TC;
    cin>>TC;

    while(TC--) {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<bfs(a,b,c)<<endl;
    }
    return 0;
}
