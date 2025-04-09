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
    int n, a, b, c, d;
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // (0, 1)
        // if (1, 0) on the right
        // cost is min(a, d)
        // count(0, 1) so far > count(1, 0) so far
        // count all arrays aside from those where count(0, 1) so far <=
        // (contd.) count(1, 0) so far

        // if (1, 0) on the left
        // cost is min(b, c)

        // (1, 0)
        // if (0, 1) on the right
        // cost is min(b, c)

        // if (0, 1) on the left
        // cost is min(a, d)
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
