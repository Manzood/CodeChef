#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    bool ans = true;
    if ((n & 1) == 0) {
        if (n == 1 && k == 0) ans = false;
    } else {
        if (k == 0) ans = false;
    }
    ans ? printf("Yes\n") : printf("No\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
