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
    if(k == 1 || k == 2){
	    ++ans;
	    return 1;
	} else {
	    ++ans;
        return fib(k-1) + fib(k-2);
	}
}
