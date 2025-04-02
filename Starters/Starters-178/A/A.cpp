#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int a = 2, b = (n & 1) ? n : n - 1;
    if (b - a < k || (a * b) - 1 < 2 * k) {
        printf("-1 -1\n");
    } else {
        printf("%lld %lld\n", a, b);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
