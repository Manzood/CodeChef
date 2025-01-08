#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<bool> erased(n, false), used(n, false);
    vector<bool> any(n, false);
    for (int i = 0; i < n; i++) {
        used[p[i]] = true;
        if (!used[i]) erased[i] = true;
        if (a[i] == 0 && erased[i]) any[i] = true;
        a[i] = a[p[i]];
    }
    int fin = 0;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (fin != 0) {
                if (fin != a[i]) {
                    possible = false;
                }
            } else {
                fin = a[i];
            }
        }
    }
    int ans = 1;
    if (fin == 0) ans = m;
    if (!possible) ans = 0;
    int cnt = 0;
    for (auto x : any) cnt += (int)x;
    for (int i = 0; i < cnt; i++) {
        ans *= m;
        ans %= MOD;
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
