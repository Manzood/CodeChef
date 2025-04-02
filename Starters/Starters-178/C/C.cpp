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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> dp(n, 0), best(n + 1, n + 1);
    dp[0] = 1, best[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != 0) {
            dp[i] = dp[i - 1] + 1;
            dp[i] = min(dp[i], best[a[i]] + 1);
            dp[i] = min(dp[i], best[0] + 1);
        } else {
            dp[i] = 1;
        }
        best[a[i]] = min(best[a[i]], dp[i - 1]);
    }
    printf("%lld\n", dp[n - 1]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
