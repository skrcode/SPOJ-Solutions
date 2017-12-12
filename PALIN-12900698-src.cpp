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
    int TC;
    cin>>TC;

    while(TC--) {
        string str;
        cin>>str;
        bool foo = false;
        int len = str.size();
        vi arr;
        arr.pb(0);
        bool checking = false;
        for(int i=0;i<len;i++) {
            if(str[i]!='0' || checking) {
            arr.pb(str[i]-'0');
            checking = true;
            }
        }
        len = arr.size()-1;

        bool isadded = false;
        bool issame = false;
        //basecase1
        bool check = true;
        for(int i=1;i<arr.size();i++)
            if(arr[i]!=9)check = false;
        if(check) {
            for(int i=1;i<=len+1;i++) {
                if(i==1 || i==len+1)cout<<"1";
                else cout<<"0";
            }
            cout<<endl;
            continue;
        }
        //basecase2
        check = true;
        for(int i=0;i<len/2+(len%2);i++)
            if(arr[-i+len/2+(len%2)]!=arr[i+len/2+1])check = false;
        if(check) {
            int x = len/2+(len%2);
            int y = len/2+1;
            int carry = 1;
            while(1) {
                if(x == y) {
                    int c;
                    c = (arr[x]+carry)/10;
                    arr[x] = (arr[x]+carry)%10;
                    carry = c;
                }
                else {
                    int c;
                    c = (arr[x]+carry)/10;
                    arr[x] = (arr[x]+carry)%10;
                    arr[y] = arr[x];
                    carry = c;
                }
                if(carry == 0)break;
                x--;
                y++;
           }
           for(int i=1;i<arr.size();i++)cout<<arr[i];
           cout<<endl;
           continue;
        }
        for(int i=0;i<len/2+(len%2);i++) {
            int p = len/2+(len%2)-i;
            int q = len/2+1+i;
            if(arr[p]==arr[q])issame = true;
        }
        if(!issame)
        for(int i=0;i<len/2+(len%2);i++) {
            int p = len/2+(len%2)-i;
            int q = len/2+1+i;
            if(isadded){arr[q] = arr[p];continue;}
            if(arr[p]>arr[q]){arr[q] = arr[p];isadded = true;}
            else
            if(arr[p]<arr[q]){arr[p]++;arr[q] = arr[p];isadded = true;}
        }
        if(issame) {
            for(int i=0;i<len/2+(len%2);i++) {
                int p = len/2+(len%2)-i;
                int q = len/2+1+i;
                if(isadded){arr[q] = arr[p];continue;}
                if(arr[p]>arr[q]){arr[q] = arr[p];isadded = true;}
                else
                if(arr[p]<arr[q]) {
                    int x = len/2+(len%2);
                    int y = len/2+1;

                    int carry = 1;
                    while(1) {
                        if(x == y) {
                            int c;
                            c = (arr[x]+carry)/10;
                            arr[x] = (arr[x]+carry)%10;
                            carry = c;
                        }
                        else {
                            int c;
                            c = (arr[x]+carry)/10;
                            arr[x] = (arr[x]+carry)%10;
                            arr[y] = arr[x];
                            carry = c;
                        }
                        if(carry == 0)break;
                        x--;
                        y++;
                    }
                    isadded = true;
                    i--;
                }

            }
        }
        int is = false;
        for(int i=0;i<arr.size();i++)
            if( (arr[i] || is)) {
                cout<<arr[i];
                is = true;
            }
        //if(foo!=-1)cout<<foo;
        cout<<endl;
    }
    return 0;
}
