#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int x, y;
    scanf("%lld%lld", &x, &y);
    int ans = 0;
    if (y > 0) ans += 2 * y - 1;
    if (x - y > 0 && y > 0) ans++;
    ans += x - y;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
