#include <stdio.h>
#include <string.h>

int main() {
    char number[301];
    scanf("%s", number);

    int length = strlen(number);
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = (sum * 10 + (number[i] - '0')) % 6;
    }

    if (sum == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}