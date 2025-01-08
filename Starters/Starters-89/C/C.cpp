#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)1e7 + 1;

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> a(n), b(m);
    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        A += a[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        B += b[i];
    }
    int ans = (int)1e18;
    for (int x = 0; x < max(5 * m + 1, 100LL); x++) {
        int rhs = n * (B + x) - A * (m + x);
        int best = MX;
        for (int i = 23; i >= 0; i--) {
            int val = (1LL << i);
            if (best - val >= 0) {
                int cur = best - val;
                int lhs = cur * (k * (m + x) - (B + x));
                if (lhs > rhs) best = cur;
            }
        }
        ans = min(ans, best + x);
        if (best == 0) break;
    }
    if (k == 1) ans = -1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
