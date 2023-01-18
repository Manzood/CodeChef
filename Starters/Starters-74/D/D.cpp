#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n), c(m), suff(m + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        suff[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = m - 1; i >= 0; i--) {
        suff[i] += suff[i + 1];
    }
    int ans = 0;
    vector<int> cnt(m + 1, 0);
    for (int p = 1; p <= m; p++) {
        for (int i = p; i <= m; i += p) {
            cnt[p] += suff[i];
        }
        ans = max(ans, cnt[p] * c[p - 1]);
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
