#include <cstdio>
int sum_positive_number(int n);

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	if(a==b || a<=0 || b<=0)
		printf("No");
		
	if(sum_positive_number(a)==b && sum_positive_number(b)==a)
		printf("Yes");
	else
		printf("No");
		
	return 0;	
}

int sum_positive_number(int n)
{
	int temp = 1;
	for(int i=2; i<=n/2; i++)
		if(n%i==0)
			temp += i;
			
	return temp;
}