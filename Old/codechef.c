#include <stdio.h>

int main() {
    int n, i, c;
    scanf("%d", &n);
    int flag = 0;
    int x[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &c);
        x[c] = 1;
    }

    for (i = 0; i < n; i++) {
        if (x[i] != 1) {
            x[i] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &c);
        if (x[c] == 1) x[c] = 0;
    }

    for (i = 0; i < n && flag == 0; i++) {
        if (x[c] == 1) {
            printf("No");
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("Yes");
    }
    return 0;
}
