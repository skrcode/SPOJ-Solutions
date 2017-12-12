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


#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)


typedef long long int64;
typedef double float64;

//START

int mul(int temp[10000],int x,int len)

{

    int t,i;

    t=0;

    for(i=0;i<len;i++)

    {

        t=temp[i]*x+t;

        temp[i]=t%10;

        t=t/10;

    }

    while(t!=0)

    {

        temp[i++]=t%10;
        t/=10;

        len=i;

    }

    return len;



}

void fac(int N)

{

    int i,temp[10000];

    int len=1;

    temp[0]=1;



    rep(i,2,N)

        len=mul(temp,i,len);

    for(i=len-1;i>=0;i--)

        printf("%d",temp[i]);

}

int main()

{

    int T;

    int N;


    scanf("%d",&T);


    while(T--)

    {

        scanf("%d",&N);



        fac(N);
        printf("\n");

    }



    return EXIT_SUCCESS;

}

