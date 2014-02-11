#include<stdio.h>
#include<math.h>
#define a 110351
#define b 123
int num=10;
int rnd(int,int);
int rnd(int n,int num)
{
	
	n=((n)*a + b)%num;
	return n;
}

main()
{
	int i;
	for(i=0;i<100;i++)
	printf("%d\n",rnd(i,num));
}
