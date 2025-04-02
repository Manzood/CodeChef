#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

template <typename T>
T getpow(T a, T b, T m) {
    T result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int low = 0, high = 0;
    int cnt = 0, sign = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        int val = getpow(2LL, i, MOD);
        (cur += (val * sign) % MOD) %= MOD;
        if (cur < 0) cur += MOD;
        if (sign == 1) {
            high = cur;
        } else {
            low = cur;
        }
        cnt++;
        if (cnt % 2 == 0) {
            sign *= -1;
        }
    }
    int ans = high - low;
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
