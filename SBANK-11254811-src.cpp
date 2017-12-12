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

struct account
{
    int control;
    int64 code;
    int t1,t2,t3,t4;
}a[100005];

bool myfnc(account x,account y)
{
    if(x.control!=y.control) return x.control<y.control;
    if(x.code!=y.code)       return x.code<y.code;
    if(x.t1!=y.t1)           return x.t1<y.t1;
    if(x.t2!=y.t2)           return x.t2<y.t2;
    if(x.t3!=y.t3)           return x.t3<y.t3;
    if(x.t4!=y.t4)           return x.t4<y.t4;
    return false;
}

int main()
{//takeinput();
    int TC;

    scanf("%d",&TC);

    while(TC--)
    {
        int N;

        scanf("%d",&N);

        rep(i,0,N-1)
        {
            scanf("%d %lld %d %d %d %d",&a[i].control,&a[i].code,&a[i].t1,&a[i].t2,&a[i].t3,&a[i].t4);//debug1(a[i].control)
        }

        sort(a,a+N,myfnc);
        a[N].control=-1;
        int count = 1;
        for(int i=0;i<N;i++)
        {
            if((a[i].control==a[i+1].control )&& (a[i].t1 == a[i+1].t1 )&& (a[i].t2 == a[i+1].t2 )&& (a[i].t3 == a[i+1].t3 )&& (a[i].t4 == a[i+1].t4) ){ count++;}
            else
            {
                cout<<setfill('0')<<setw(2)<<a[i].control<<" ";

                cout<<setfill('0')<<setw(8)<<a[i].code<<" ";

                cout<<setfill('0')<<setw(4)<<a[i].t1<<" ";

                cout<<setfill('0')<<setw(4)<<a[i].t2<<" ";

                cout<<setfill('0')<<setw(4)<<a[i].t3<<" ";

                cout<<setfill('0')<<setw(4)<<a[i].t4<<" ";
                printf("%d\n",count);
                count=1;

            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

