#include<stdio.h>
double Pn(int n,double x);
int main()
{
	int n;
	double x;
	scanf("%d %lf",&n,&x);
	double result=Pn(n,x);
	printf("%.4f",result);
	return 0;
}
double Pn(int n,double x)
{
	if(n<0){
		return -1;
	}
	else if(n==0){
		return 1;
	}
	else if(n==1){
		return x;
	}
	else{
		return ((2*n-1)*x-Pn(n-1,x)-(n-1)*Pn(n-2,x))/n;
	}

}