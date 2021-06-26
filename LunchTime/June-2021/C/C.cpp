#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        while (b % 2 == 0) {
            b /= 2;
        }
        if (b == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
