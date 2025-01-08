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
    vector<bool> appears(n, false);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%lld", &x);
        x--;
        appears[x] = true;
    }
    int ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (appears[i]) continue;
        int higher = n - 1 - i;
        ans *= higher;
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
