#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int val = __gcd(a, b);
    while (val > 1) {
        b = b / val;
        val = __gcd(a, b);
    }
    bool ans = b > 1;
    ans ? printf("NO\n") : printf("YES\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
