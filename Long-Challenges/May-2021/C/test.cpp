#include "bits/stdc++.h"
using namespace std;

int32_t main () {
    int n = 0;
    int cnt = 0;
    for (int i = 0; i <= 127; i++) {
        if ((n ^ (n + 1)) == ((n + 2) ^ (n + 3))) {
            cnt++;
            printf("%d ", n);
        }
        n++;
    }
    printf("%d\n", cnt);
}
