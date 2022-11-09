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
    sort(a.begin(), a.end());
    int ans = n;
    bool pos = true;
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % a[0] != 0) {
            pos = false;
            break;
        }
        if (a[i] > a[0]) cur++;
    }
    if (pos) ans = min(ans, cur);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
