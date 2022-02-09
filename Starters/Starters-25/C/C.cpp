#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int x, m;
    scanf("%lld%lld", &x, &m);
    int cur = 0;
    int inv = 1;
    int ops = 0;
    while (cur < x) {
        if (cur + inv > x) {
            inv -= x - cur;
            cur = x;
        } else {
            cur += inv;
            inv = cur;
        }
        ops++;
        // debug (inv);
    }
    int ans = 0;
    if (ops <= m) {
        ans = 1;
        m -= ops;
        ans += m;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
