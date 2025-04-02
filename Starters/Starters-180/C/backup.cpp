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
    // taking the first i elements, what is the number of strictly increasing
    // subsequences with final value at most k
    if (a[0] == -1) {
        for (int i = 1; i <= k; i++) dp[1][i] = i;
    } else {
        for (int i = a[0]; i <= k; i++) dp[1][i] = 1;
    }
    if (test == 1) debug(dp);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (a[i - 1] == -1) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        } else {
            for (int j = a[i - 1]; j <= k; j++) {
                dp[i][j] += dp[i - 1][a[i - 1] - 1];
            }
        }
    }
    printf("%lld\n", dp[n][k]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
