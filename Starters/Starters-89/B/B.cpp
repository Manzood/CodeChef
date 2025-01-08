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
    vector<int> a(n), get(n + 1);
    int ind = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == n) ind = i;
        get[a[i]] = i;
    }
    int l = ind, r = ind;
    int mi = n;
    int ans = 1;
    for (int i = n - 1; i > 1; i--) {
        ind = get[i];
        if (ind < l) {
            while (l > ind) {
                l--;
                mi = min(mi, a[l]);
            }
        } else if (ind > r) {
            while (r < ind) {
                r++;
                mi = min(mi, a[r]);
            }
        }
        if (i == mi) {
            ans = n - mi + 1;
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
