#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r, x;
    scanf("%lld%lld%lld", &l, &r, &x);
    if (!(x >= l && x <= r)) {
        printf("0\n");
        return;
    }
    int ans = (l - 1) ^ x;
    ans = min(ans, (r + 1) ^ x);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
