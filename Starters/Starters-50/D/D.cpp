#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int steps = 0;
    for (int i = n - 1; i >= 0; i--) {
        int val = steps * y;
        a[i] -= val;
        if (a[i] > 0) {
            int cnt = a[i] / max(x, y);
            if (a[i] % max(x, y) > 0) cnt++;
            steps += cnt;
        }
    }
    printf("%lld\n", steps);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
