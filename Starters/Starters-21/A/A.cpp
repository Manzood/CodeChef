#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    int ans = (x + y) % 2;
    printf("%lld\n", ans);
}

int32_t main () {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
