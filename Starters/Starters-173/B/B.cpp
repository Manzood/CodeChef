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
    set<int> s;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (s.count(a[i])) ans = a[i];
        s.insert(a[i]);
    }
    if (ans > 0) {
        printf("1\n%lld\n", ans);
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
