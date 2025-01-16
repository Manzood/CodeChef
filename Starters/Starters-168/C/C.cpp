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
    vector<int> a(n), pref(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i] = a[i];
        if (i > 0) pref[i] ^= pref[i - 1];
    }
    vector<vector<int>> adj(n);
    map<int, int> seen;
    seen[0] = -1;
    for (int i = 0; i < n; i++) {
        if (seen.count(pref[i])) {
            adj[seen[pref[i]] + 1].push_back(i);
        }
        seen[pref[i]] = i;
    }
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = a[i];
        if (!adj[i].empty()) {
            dp[i] += dp[adj[i][0]];
        }
        ans = max(dp[i], ans);
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
