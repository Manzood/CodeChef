#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> seconds(n, 0);
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            a[i] = a[i + 1];
            seconds[i] = seconds[i + 1] + 1;
            ans = max(ans, seconds[i]);
        }
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
