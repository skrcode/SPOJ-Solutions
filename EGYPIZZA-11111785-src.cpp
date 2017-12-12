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

int main()
{
    //takeinput();
    int n;

    float val[100005];
    scanf("%d",&n);

    rep(i,0,n-1)
    {
        float x,y;
        scanf("%f/%f",&x,&y);
        val[i]=x/y;
    }

    int count1by2=0;
    int count1by4=0;
    int count3by4=0;
    for(int i=0;i<n;i++)
    {
        count1by2+=(val[i]==0.50);
        count1by4+=(val[i]==0.25);//
        count3by4+=(val[i]==0.75);//
    }//debug1(count1by2);debug1(count1by4);debug1(count3by4);
    int sum=0;
    sum+=(count1by2/2);
    count1by2=count1by2%2;

    if(count3by4>=count1by4)
    {
        count3by4-=count1by4;
        sum+=count1by4;
        count1by4=0;
        sum+=(count3by4+count1by2);
    }
    if(count3by4<count1by4)
    {
        count1by4-=count3by4;
        sum+=count3by4;
        count3by4=0;
        if(count1by2==1)
        {
            if(count1by4>=2)
            {
                count1by4-=2;
                sum++;
            }
            else
            {
                sum++;
                count1by4=0;
            }
        }
        else
        {
            sum+=count1by4/4;
            count1by4=count1by4%4;
            sum+=(count1by4!=0);
        }

    }
    cout<<sum+1<<endl;

    return EXIT_SUCCESS;
}
