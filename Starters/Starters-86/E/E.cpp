#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = 5005;
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

vector<vector<int>> ncr(MX, vector<int>(MX, 0));
void precompute() {
    for (int i = 0; i < MX; i++) ncr[i][0] = 1;
    for (int i = 1; i < MX; i++) {
        for (int j = 1; j <= i; j++) {
            (ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1]) %= MOD;
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, X;
    scanf("%lld%lld", &n, &X);
    int ans = 0;
    for (int x = 1; x < X; x++) {
        for (int i = 1; i < n; i++) {
            int val = min(i, n - i);
            int num = getpow(x, i, MOD) * getpow(X - x, n - i, MOD) % MOD;
            num = num * ncr[n][i] % MOD;
            (ans += val * num % MOD) %= MOD;
        }
    }
    ans = ans * 2 % MOD;
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
