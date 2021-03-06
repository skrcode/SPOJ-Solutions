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

int main() {
    int n;
    cin>>n;
    string str;
    cin>>str;

    int len = str.size();
    int prev = 'X';
    for(int i=0;i<len;i+=2) {
        if(str[i]=='A') {
            if(str[i+1] == 'B'){if(prev!='C'){cout<<"CD";prev = 'D';}else {cout<<"DC";prev = 'C';}}
            if(str[i+1] == 'C'){if(prev!='B'){cout<<"BD";prev = 'D';}else {cout<<"DB";prev = 'B';}}
            if(str[i+1] == 'D'){if(prev!='C'){cout<<"CB";prev = 'B';}else {cout<<"BC";prev = 'C';}}
        }
        if(str[i]=='B') {
            if(str[i+1] == 'C'){if(prev!='A'){cout<<"AD";prev = 'D';}else {cout<<"DA";prev = 'A';}}
            if(str[i+1] == 'D'){if(prev!='A'){cout<<"AC";prev = 'C';}else {cout<<"CA";prev = 'A';}}
            if(str[i+1] == 'A'){if(prev!='C'){cout<<"CD";prev = 'D';}else {cout<<"DC";prev = 'C';}}
        }
        if(str[i]=='C') {
            if(str[i+1] == 'A'){if(prev!='B'){cout<<"BD";prev = 'D';}else {cout<<"DB";prev = 'B';}}
            if(str[i+1] == 'B'){if(prev!='A'){cout<<"AD";prev = 'D';}else {cout<<"DA";prev = 'A';}}
            if(str[i+1] == 'D'){if(prev!='A'){cout<<"AB";prev = 'B';}else {cout<<"BA";prev = 'A';}}
        }
        if(str[i]=='D') {
            if(str[i+1] == 'A'){if(prev!='B'){cout<<"BC";prev = 'C';}else {cout<<"CB";prev = 'B';}}
            if(str[i+1] == 'B'){if(prev!='C'){cout<<"CA";prev = 'A';}else {cout<<"AC";prev = 'C';}}
            if(str[i+1] == 'C'){if(prev!='A'){cout<<"AB";prev = 'B';}else {cout<<"BA";prev = 'A';}}
        }
    }
    cout<<endl;
    return 0;
}
