#include <stdio.h>
 
int times = 0;

int fibonacci(int n) {

    times++;
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
 
int main() {
    int n;
    scanf("%d", &n);

    printf("%d,", fibonacci(n));
    printf("%d", times);

    return 0;
}