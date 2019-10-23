#include "uhead.h"
void show(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

void urand(int a[],int n)
{
	srand((int)time(0));
	int i,j;
	for(i=0;i<n;i++)
	{
		j=rand()%1000+1;
		a[i]=j;
	}
}
