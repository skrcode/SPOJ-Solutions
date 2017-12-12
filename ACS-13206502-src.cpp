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
vector < vector <int> > grid(10000005);
int revx[10000005];
int revy[10000005];

void disp() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++)cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}

void r(int x,int y) {
    for(int i=0;i<5678;i++) {
        revx[grid[x][i]] = y;
        revx[grid[y][i]] = x;
        swap(grid[x][i],grid[y][i]);
    }
}
void c(int x,int y) {
    for(int i=0;i<1234;i++) {
        revy[grid[i][x]] = y;
        revy[grid[i][y]] = x;
        swap(grid[i][x],grid[i][y]);
    }
}

int main() {//takeinput();
    int n = 1234*5678;
    int k = 1;
    for(int i=0;i<1234;i++)
        for(int j=1;j<=5678;j++) {
            grid[i].pb(k++);
            revx[k-1] = i;
            revy[k-1] = j-1;
        }
    char code;
    while(scanf(" %c",&code)!=EOF) {//disp();
        if(code == 'R') {
            int x,y;
            cin>>x>>y;
            r(x-1,y-1);
            continue;
        }
        if(code == 'C') {
            int x,y;
            cin>>x>>y;
            c(x-1,y-1);
            continue;
        }
        if(code == 'Q') {
            int x,y;
            cin>>x>>y;
            cout<<grid[x-1][y-1]<<endl;
            continue;
        }
        if(code == 'W') {
            int x;
            cin>>x;
            cout<<revx[x]+1<<" "<<revy[x]+1<<endl;
            continue;
        }
    }

    return 0;
}
