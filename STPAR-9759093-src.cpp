//SKRCODE
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<iomanip>
#include<deque>

using namespace std;
#define eps 0.00000001
typedef long long int64;
typedef long int32;

//STACK

int main()
{
    int N,i,trucks[1001],stacks[1001],key,top;

    scanf("%d",&N);

    while(N)
    {
        key=1;
        top=-1;

        for(i=0;i<N;i++)
            scanf("%d",&trucks[i]);

        for(i=0;i<N;i++)
        {
            if(trucks[i]!=key)
            {
                if(stacks[top]==key && top!=-1)
                {
                    key++;
                    top--;
                    i--;
                    continue;
                }

                if(trucks[i]>stacks[top] && top!=-1)
                {
                    printf("no\n");
                    break;
                }

                stacks[++top]=trucks[i];

            }
           else
               key++;
        }
        if(i==N)
            printf("yes\n");

        scanf("%d",&N);
    }

    return EXIT_SUCCESS;
}

