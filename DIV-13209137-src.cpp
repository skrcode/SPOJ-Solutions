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
int cnt[1000005];
bool is[100005];
int arr[1000005];
void sieve(int n) {
    for(int i=1;i*i<=n;i++)
        for(int j=i*i;j<=n;j+=i) {
            cnt[j]+=2;
            if(i*i==j)cnt[j]--;
        }
    for(int i=1;i*i<=n;i++)
        if(cnt[i]<=2)
        for(int j=i*i;j<=n;j+=i)
            if(cnt[i]==2 && cnt[j/i]==2 && j!=i*i){is[j]=true;}

}

int main() {//takeoutput();
    sieve(1000000);
    int ind = 1;
    for(int i=1;i<=1000000;i++)
        if(is[cnt[i]]) {
            arr[ind++]=i;
            //debug1(i);
        }
    for(int i=9;i<=ind-1;i+=9)
        printf("%d\n",arr[i]);

    return 0;
}
