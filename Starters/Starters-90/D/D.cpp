#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)2e5 + 5;
constexpr int MOD = (int)1e9 + 7;

vector<int> fact(MX, 1);
void precompute() {
    for (int i = 2; i < MX; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

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

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x - 1 > i) continue;
        int ncr = fact[i];
        int val = (fact[x - 1] * fact[i - x + 1]) % MOD;
        (ncr *= inv(val, MOD)) %= MOD;
        int p = getpow(2LL, n - i - 1, MOD);
        (p *= ncr) %= MOD;
        (ans += p) %= MOD;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
