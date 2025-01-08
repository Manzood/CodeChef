#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    if (!(n & 1)) {
        printf("-1\n");
        return;
    }
    int val = 1;
    for (int i = 0; i < n / 2; i++) {
        printf("%lld %lld ", val, n - val);
        val += 2;
    }
    printf("%lld\n", n);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
