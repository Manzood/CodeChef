#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX_N = 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(MX_N, vector<int>(2, 1)));
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < MX_N; j++) {
            int val = (1LL << j);
            if (j > 0) dp[i][j] = dp[i][j - 1];
            if (a[i] > a[j]) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + 1);
            } else {
                dp[i][j][0] = 1;
            }
            if ((a[i] ^ val) > (a[i - 1] ^ val)) {
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + 1);
            } else {
                dp[i][j][1] = 1;
            }
            ans = max({ans, dp[i][j][1], dp[i][j][0]});
        }
        if (test == 3) debug(ans);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
