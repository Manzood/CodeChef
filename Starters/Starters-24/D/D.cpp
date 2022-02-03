#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int x, a, b;
    scanf("%lld%lld%lld", &x, &a, &b);
    if (b > a) {
        printf("-1\n");
        return;
    }
    int n = (x * b) / a;
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) sum += i;
            else sum += i + n / i;
        }
    }
    if (sum == x) {
        printf("%lld\n", n);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
