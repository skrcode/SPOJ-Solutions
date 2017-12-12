/*
   Author : skrcode
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

int main() { //takeinput();
    string str;
    while(cin>>str) {
        int len = str.size();
        bool is1 = false,is2 = false;
        if(str[0] == '_'){is1 = true;is2 = true;}
        if(str[len-1] == '_'){is1 = true;is2 = true;}
        if(isupper(str[0])){is1 = true;is2 = true;}
        for(int i=0;i<len;i++) {
            if(str[i] == '_' && str[i+1] == '_'){is1 = true; is2=true;}
            if(str[i] >= 'A' && str[i] <= 'Z')is1 = true;
            if(str[i] == '_')is2 = true;
        }
        if(is1 && is2) {
            cout<<"Error!\n";
            continue;
        }
        if(is1) {
            for(int i=0;i<len;i++)
                if(str[i] >= 'A' && str[i] <='Z')cout<<"_"<<char(tolower(str[i]));
                else cout<<str[i];
            cout<<endl;
        }
        else {
            cout<<str[0];
            for(int i=1;i<len;i++)
                if(str[i-1] == '_')cout<<char(toupper(str[i]));
                else if(str[i]!='_')cout<<str[i];
            cout<<endl;
        }
    }
    return 0;
}
