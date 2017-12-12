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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string,int> msi;

#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define trvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define trmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define pb push_back
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
//memset(dist, MEMSET_INF, sizeof dist);
//memset(dp_memo, -1, sizeof dp_memo);
//memset(arr, 0, sizeof arr);

typedef long long int64;
typedef double float64;

//START

int pref(char x)
{
    switch(x)
    {
        case '(' : return 0;
                   break;
        case '*' :
        case '/' : return 1;
                   break;
        case '+' :
        case '-' : return 2;
                   break;
        case '^' : return 3;
                   break;           
    }
}

int main()
{
    int T,i,length;
    stack<char> mystack;
    char exp[1000];

    scanf("%d",&T);

    while(T--)
    {
        scanf("%s",exp);

        length=strlen(exp);

        for(i=0;i<length;i++)
        {
            if(isalpha(exp[i]))
                printf("%c",exp[i]);
            else
            {
                if(mystack.empty() || exp[i]=='(')
                    mystack.push(exp[i]);
                else
                {
                    if(exp[i]==')')
                    {
                        while(mystack.top()!='(')
                        {
                            printf("%c",mystack.top());
                            mystack.pop();
                        }
                        mystack.pop();
                        continue;
                    }
                    if(pref(mystack.top())>=pref(exp[i]))
                    {
                        while(pref(mystack.top())>=pref(exp[i]))
                        {
                            printf("%c",mystack.top());
                            mystack.pop();
                        }
                        mystack.push(exp[i]);
                    }
                    else
                        mystack.push(exp[i]);
                }
            }
        }
        while(!mystack.empty())
        {
            printf("%c",mystack.top());
            mystack.pop();
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
