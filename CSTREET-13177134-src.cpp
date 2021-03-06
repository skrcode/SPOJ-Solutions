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

int pset[1005];
int findset(int i) { return pset[i] == i?i:pset[i] = findset(pset[i]);}
bool issameset(int u,int v) { return findset(u)==findset(v); }

void unionset(int i,int j) { pset[findset(i)] = findset(j); }

int main() {// takeinput();
    int TC;
    cin>>TC;

    while(TC--) {
        int c;
        cin>>c;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)pset[i]=i;
        vector < pair < int,pair<int,int> > > EdgeList;
        while(m--) {
            int u,v,f;
            cin>>u>>v>>f;
            EdgeList.pb(mp(f,mp(u,v)));
        }
        sort(EdgeList.begin(),EdgeList.end());
        int ans = 0;
        for(int i=0;i<EdgeList.size();i++) {
            pair <int,pair<int,int> > x;
            x = EdgeList[i];
            if(issameset(x.second.first,x.second.second))continue;
            unionset(x.second.first,x.second.second);
            ans+=x.first;
        }
        cout<<ans*c<<endl;
    }
    return 0;
}
