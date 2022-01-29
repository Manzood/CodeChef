#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    if ((k - 1 == 0 && n != 1) || k > n) {
        printf("-1\n");
        return;
    }
    vector <int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin() + k - 1, a.end());
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
