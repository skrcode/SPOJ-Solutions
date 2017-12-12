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
#define lsegtree(N) (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)))

typedef long long int64;
typedef double float64;

//START

int main() {
    string str;

    while(cin>>str) {

        if(str[0] == '0') {
            cout<<"0\n";
            continue;
        }
        if(str[0] == '1' && str.size()==1) {
            cout<<"1\n";
            continue;
        }
        int len = str.size();
        vi arr;
        arr.pb(0);
        for(int i=0;i<len;i++)
            arr.pb(str[i]-'0');
        for(int i=len;i>=1;i--) {
            if(arr[i]>=1) {
                arr[i] -=1;
                break;
            }
            else {
                arr[i]+=10;
                arr[i]-=1;
            }
        }

        int carry = 0;
        for(int i=len;i>=0;i--) {
            arr[i] = (arr[i])*2+carry;
            carry = arr[i]/10;
            arr[i] = arr[i]%10;
        }
        for(int i=0;i<=len;i++){if(i==0 && arr[i]==0)continue;cout<<arr[i];}
        cout<<endl;
    }
    return 0;
}
