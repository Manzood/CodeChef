#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;
long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    if (n == 1) {
        printf("1\n");
        return;
    }
    int left = 0;
    if (l <= n / 2) {
        if (r <= n / 2) {
            left = r - l + 1;
        } else {
            left = n / 2 - l + 1;
        }
    }
    int right = 0;
    if (r > n / 2) {
        if (l > n / 2) {
            right = r - l + 1;
        } else {
            right = r - (n / 2);
        }
    }
    debug(left, right);
    int ans = 0;
    // n / 2 ( 2 * a + (n - 1) * d);
    int start = l;
    ans +=
        ((left *
          ((((2 * (2 * start - 1)) % MOD) + (((left - 1) * 2) % MOD)) % MOD)) %
         MOD) *
        inv(2, MOD);
    ans %= MOD;
    ans += ((right * (4 + (((right - 1) * 2) % MOD))) % MOD) * inv(2, MOD);
    ans %= MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
