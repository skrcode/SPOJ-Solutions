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

char str[100005];
char t[100005];
int len;
int sa[100005];
int pos[100005];
int tmp[100005];
int gap;

bool f(int i,int j) {
    if(pos[i]!=pos[j]) return pos[i]<pos[j];

    i += gap/2;
    j += gap/2;
    return i<len && j<len ? pos[i]<pos[j] : i<j;
}

void build() {
    for(int i=0;i<len;i++) {
        sa[i] = i;
        pos[i] = str[i];
    }
    for(gap = 1;;gap<<=1) {
        sort(sa,sa+len,f);
        for(int i=1;i<len;i++)tmp[i] = tmp[i-1] + f(sa[i-1],sa[i]);
        for(int i=0;i<len;i++)pos[sa[i]] = tmp[i];
        if(tmp[len-1] == len-1)break;
    }
}


int main() {//takeinput();
    int TC;
    cin>>TC;

    while(TC--) {
        cin>>str;
        strcpy(t,str);
        strcat(str,t);
        len = strlen(str);
        build();
        for(int i=0;i<len;i++)if(sa[i]<len/2) {
            cout<<sa[i]+1<<endl;
            break;
        }
    }

    return 0;
}
