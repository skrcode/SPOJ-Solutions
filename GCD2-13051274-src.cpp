#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define pb push_back
//START
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main() { //takeinput()
    int TC;
    cin>>TC;

    while(TC--) {
        string s;int b;cin>>b;
        cin>>s;
        if(!b){cout<<s<<endl;continue;}
        int l = s.size();
        vector <int> a;
        for(int i=0;i<l;i++)
            a.pb(s[i]-'0');
        int den = 0;
        int x = 0;
        for(int i=0;i<a.size();i++) {
            x = (x*10+a[i])%b;
        }
        cout<<gcd(b,x);
        cout<<endl;
    }
    return 0;
}
