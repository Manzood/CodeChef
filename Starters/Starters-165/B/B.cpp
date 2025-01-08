#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x1, y1, z1, x2, y2, z2, k;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &z1, &x2, &y2, &z2, &k);
    vector<int> a = {abs(x2 - x1), abs(y2 - y1), abs(z2 - z1)};
    sort(a.begin(), a.end());
    int ans = 0;
    if (a[2] <= (a[0] + a[1] + 1) * k) {
        ans = a[2] + a[0] + a[1];
    } else {
        ans = a[2] + a[0] + a[1];
        int rem = a[2] - (a[0] + a[1] + 1) * k;
        int moves = (rem + k - 1) / k;
        if (moves & 1) {
            moves++;
        }
        ans += moves;
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
