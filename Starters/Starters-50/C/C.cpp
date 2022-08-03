#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    bool possible = false;
    int l = x / 2;
    int r = l;
    if (x & 1) r = x / 2 + 1;
    int ml = -1, mr = -1;
    for (int i = 1; i * i <= y; i++) {
        if (y % i) continue;
        int val = y / i;
        if ((i < l && val < l) || (i > r && val > r)) {
            ml = i;
            mr = val;
            possible = true;
        }
    }
    if (possible) {
        printf("%lld %lld\n%lld %lld\n", l, r, ml, mr);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
