#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

int factorial(int n) {
    if (n == 0) return 1;
    int factorial = 1;
    for (int i = 2; i <= n; i++) factorial = (factorial * i) % mod;
    return factorial;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    int ans = nCr(n, k);
    ans %= mod;
    int pow = 1;
    for (int i = 0; i < ans; i++) {
        pow *= 2;
        pow %= mod;
    }
    printf("%lld\n", pow);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
