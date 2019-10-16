#include "dylib.h"
#include<stdio.h>
int main()
{
	//int a[5]={12,0,-154,7668,134};
	int a[5];
	init(a,5);
	show(a,5);
	printf("max=%4d\n",max(a,5));
	printf("sum=%4d\n",sum(a,5));
	return 0;
}
