#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        int val = a[i - 1];
        dp[i] = dp[i - 1];
        if (val == -1) {
            int tot = 0;
            for (int j = 1; j <= k; j++) {
                tot += dp[i - 1][j - 1] + 1;
                dp[i][j] += tot;
            }
        } else {
            for (int j = val; j <= k; j++) {
                dp[i][j] += dp[i - 1][val - 1] + 1;
            }
        }
    }
    debug(dp);
    printf("%lld\n", dp[n][k]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
