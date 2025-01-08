#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    int ans = 1;
    if ((a + 1) % b == 0 || (c + 1) % d == 0) {
        int rem = a % b;
        int lcm = (b * d) / __gcd(b, d);
        ans = lcm - rem;
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
