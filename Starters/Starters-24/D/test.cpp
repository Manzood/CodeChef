#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int mi = 1e18;
    for (int n = 173; n <= 177; n++) {
        int prod = 1;
        bool prime = true;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i > 1) prime = false;
                prod *= i;
                prod *= n / i;
            }
        }
        if (!prime) mi = min(mi, prod);
        debug (n, prime, prod);
    }
    debug (mi);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
