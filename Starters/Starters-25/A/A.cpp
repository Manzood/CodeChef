#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n), b(n);
    set <int> s1, s2;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        s1.insert(a[i]);
        s2.insert(b[i]);
    }
    printf("%lld\n", (int) s1.size() + s2.size());
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
