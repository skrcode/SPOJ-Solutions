//Number of trailing zeroes of factorial of a number

 

#include<stdio.h>

#include<math.h>

//Fnc to return number of trailing zeroes of factorial of a number

int compute(int n)
{

 int i=1,count5=0;
 int temp;
 int remainder=10;
 int power;
 
 while(remainder>=1)
 {
  power=pow(5,i++);
  count5+=(n/power);
  remainder=n/power;
 }

return count5;

}

int main()

{

 int T,n,i=0;

 int answer[100000];

 

 scanf("%d",&T);

 

 while(i<T)

 {

  scanf("%d",&n);

  answer[i++]=n;

 }

 

 for(i=0;i<T;i++)

 printf("%d\n",compute(answer[i]));
 

 return 0;

}

