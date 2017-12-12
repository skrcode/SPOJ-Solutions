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

int dp[3005][3005];

void computedp(char str1[],char str2[])
{
    int length1=strlen(str1)-1;
    int length2=strlen(str2)-1;
//debug2(length1,length2);
    dp[0][0]=0;
    for(int i=1;i<=length1;i++)
        dp[i][0]=i;
    for(int i=1;i<=length2;i++)
        dp[0][i]=i;

    for(int i=1;i<=length1;i++)
    {
        for(int j=1;j<=length2;j++)
        {
            int opt1 = dp[i][j-1]   + 1;
            int opt2 = dp[i-1][j]   + 1;
            int opt3 = dp[i-1][j-1] +  (str1[i]!=str2[j]);
            dp[i][j]=min(opt1,min(opt2,opt3));
            //debug3(i,j,dp[i][j]);
        }
    }
}

int main()
{//takeinput();
    int TC;
    char str1[3005],str2[3005];

    scanf("%d",&TC);
    cin.ignore();

    while(TC--)
    {
        scanf("%s %s",str1,str2);

        for(int i=strlen(str1)+1;i>0;i--)
            str1[i]=str1[i-1];
        for(int i=strlen(str2)+1;i>0;i--)
            str2[i]=str2[i-1];

        computedp(str1,str2);

        printf("%d\n",dp[strlen(str1)-1][strlen(str2)-1]);
    }

    return EXIT_SUCCESS;
}
