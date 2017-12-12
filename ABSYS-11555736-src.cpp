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
const double eps = 1e-9;
const double pi = 3.14159265359;
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
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

void check(char str[]){
    int l = strlen(str);
    for(int i=0;i<l;i++)
        if(str[i]=='m')
            for(int j=i;j<l-7;j++) str[j]=str[j+7];
}

char num1[100005],num2[100005],num3[100005];
int main(){//takeinput();
    int TC;
    scanf("%d",&TC);
    cin.ignore();
    while(TC--){
        scanf("%s + ",num1);
        scanf("%s = ",num2);
        scanf("%s",num3);
        int l1=strlen(num1);
        int l2=strlen(num2);
        int l3=strlen(num3);
        int f;
        for(int i=0;i<l1;i++)if(num1[i]=='m') f=1;
        for(int i=0;i<l2;i++)if(num2[i]=='m') f=2;
        for(int i=0;i<l3;i++)if(num3[i]=='m') f=3;
        if(f==1) check(num1);
        if(f==2) check(num2);
        if(f==3) check(num3);
        int n1 = atoi(num1);
        int n2 = atoi(num2);
        int n3 = atoi(num3);
        if(f==1) printf("%d + %d = %d\n",n3-n2,n2,n3);
        if(f==2) printf("%d + %d = %d\n",n1,n3-n1,n3);
        if(f==3) printf("%d + %d = %d\n",n1,n2,n1+n2);
    }
    return 0;
}
