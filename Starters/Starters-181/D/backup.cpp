#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;
constexpr int N = 405;

template <typename T>
T exp(T a, T b, T m) {
    T result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }

    return result;
}

vector<vector<int>> ncr(N, vector<int>(N, 0)), remCnt(N, vector<int>(N, 0));
vector<int> fact(N, 1), totalRem(N, 0);

void precompute() {
    for (int i = 0; i < N; i++) ncr[i][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
            ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;

    for (int i = 2; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j += 2)
            remCnt[i][j] =
                fact[j] / (fact[j / 2] * fact[j / 2]) * exp(2LL, i - j, MOD);
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) totalRem[i] += remCnt[i][j];
}

void solve([[maybe_unused]] int test) {
    int n, a, b, c, d;
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (test == 3) debug(i, ans);
        for (int j = 0; j <= i; j++) {
            for (int k = j + 1; k <= i; k++) {
                if (j + k > i) continue;

                int val = ncr[i][j + k] * fact[j + k] / (fact[j] * fact[k]) *
                          exp(2LL, i - j - k, MOD);
                val *= ncr[n - i - 1][k - j - 1] * totalRem[n - i + j - k];

                ans += val * min(a, d);
            }
        }

        if (test == 3) debug(i, ans);
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                if (j + k > i) continue;

                int val = ncr[i][j + k] * fact[j + k] / (fact[j] * fact[k]) *
                          exp(2LL, i - j - k, MOD);
                val *= ncr[n - i - 1][j + 1 - k] * totalRem[n - i - 2 - j + k];

                ans += val * min(b, c);
            }
        }
        if (test == 3) debug(i, ans);
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
