#include<iostream>
using namespace std;
typedef long long int64;
int64 dp[1000005];
int main() {
    int TC;
    cin>>TC;
    dp[1] = 1;
    for(int64 i=2;i<=1000000;i++) {
        dp[i] = dp[i-1] + i*(i+1)/2;
        if(i%2)dp[i]+=((i+1)*(i-1)/4);
        else dp[i]+=((i*i)/4);
    }

    while(TC--) {
        int64 n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
