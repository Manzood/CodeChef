#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

template <typename T>
T getpow(T a, T b, T m) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        T prod = getpow(a, b / 2, m);
        return prod * prod % m;
    } else {
        T prod = getpow(a, b / 2, m);
        return (prod * prod % m) * a % m;
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int ans = 1;
    if (m & 1) {
        int p = getpow(m, n, MOD);
        ans = (p + 1) % MOD;
        int val = 2 * p % MOD;
        (ans *= inv(val, MOD)) %= MOD;
    } else {
        ans *= inv(2, MOD);
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
