#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int x;
    scanf("%lld", &x);
    int pow = 1;
    while (pow <= x) {
        pow *= 2;
    }
    printf("%lld %lld %lld\n", 0LL, x, x + pow);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
