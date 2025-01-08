#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int mi = INF;
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mi = min(a[i], mi);
        s += a[i];
    }
    bool ans = false;
    if (n & 1) {
        ans = !(s & 1);
        ans ? printf("CHEFINA\n") : printf("CHEF\n");
        return;
    }
    int rem = s - (n * mi);
    if (!(mi & 1)) {
        // p1 wants it to be odd
        if (!(rem & 1)) ans = true;
    }
    ans ? printf("CHEFINA\n") : printf("CHEF\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
