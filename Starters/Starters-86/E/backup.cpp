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

vector<vector<int>> cnt(MX, vector<int>(MX, 0));
void precompute() {
    for (int i = 0; i < MX; i++) {
        cnt[0][i] = 0;
        cnt[i][0] = 0;
    }
    for (int i = 1; i < MX; i++) cnt[0][i] = 1;
    for (int len = 1; len < MX; len++) {
        for (int x = 1; x < MX; x++) {
            (cnt[len][x] += cnt[len - 1][x]) %= MOD;
            (cnt[len][x] += cnt[len][x - 1]) %= MOD;
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
            int num = cnt[i][x];
            (num *= cnt[n - i][X - x]) %= MOD;
            (ans += val * num % MOD) %= MOD;
        }
    }
    (ans *= 2) %= MOD;
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
