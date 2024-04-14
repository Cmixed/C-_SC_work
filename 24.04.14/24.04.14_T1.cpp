#include<stdio.h>

int fib(int k);
int ans=0;
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d,", fib(n));
	printf("%d",ans);  
    return 0;
}

int fib(int k)
{
    ++ans;
    if(k == 1 || k == 2){
	    return 1;
	} else {
        return fib(k-1) + fib(k-2);
	}
}
