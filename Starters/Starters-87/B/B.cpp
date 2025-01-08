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
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> mxl(n, 0), mir(n, 0);
    mxl[0] = a[0];
    for (int i = 1; i < n; i++) {
        mxl[i] = max(mxl[i - 1], a[i]);
    }
    mir[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mir[i] = min(mir[i + 1], a[i]);
    }
    int ans = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!(mxl[i] > a[i] || mir[i] < a[i])) {
            ans *= 2;
            ans %= MOD;
            cnt++;
        }
    }
    if (cnt == n) ans--;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
