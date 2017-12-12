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

string str;
int64 memo[5005][5];
int64 dfs(int64 pos,int64 len,int64 sz) {
    if(pos==len && sz==1) {
        return 1;
    }
    if(memo[pos][sz]!=-1)return memo[pos][sz];
    int64 ans = 0;
    int64 num = str[pos]-'0';
    if(sz==2){pos++;num=num*10+(str[pos]-'0');pos--;}
    if(num>=1 && num<=26 && str[pos]!='0') {
        ans+=dfs(pos+sz,len,1);
        ans+=dfs(pos+sz,len,2);
    }
    return memo[pos][sz] = ans;
}

int main() {//takeinput();
    while(1) {
        cin>>str;
        if(str=="0")break;
        int64 len = str.size();
        memset(memo,-1,sizeof(memo));
        cout<<dfs(0,len,1)+dfs(0,len,2)<<endl;
    }
    return 0;
}
