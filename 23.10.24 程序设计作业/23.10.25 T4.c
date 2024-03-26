#include <stdio.h>
int sum(int a);
int main(void)
{
	int i = 0,all = 0;
	scanf("%d", &i);
	for(int j=0;j<=i;j++)
	{
		all += sum(j);
	}
	printf("%d",all);
	return 0;
}

int sum(int a)
{
	return (a+a*a)/2;
}