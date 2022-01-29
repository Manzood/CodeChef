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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    debug (n, a);
    vector <int> ans(n, n);
    bool found = false;
    vector <int> cnt(n + 1, 0);
    cnt[n] = n;
    while (!found) {
        // debug (ans);
        bool changed = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i+1]) {
                cnt[ans[i]]--;
                int val = ans[i];
                ans[i] = min(ans[i], ans[i+1] - 1);
                cnt[ans[i]]++;
                if (ans[i] < val) changed = true;
            }
        }
        if (a[n-1] < a[0]) {
            cnt[ans[n-1]]--;
            int val = ans[n-1];
            ans[n-1] = min(ans[n-1], ans[0] - 1);
            cnt[ans[n-1]]++;
            if (ans[n-1] < val) changed = true;
        }
        found = true;
        for (int i = 1; i < n; i++) {
            if (cnt[i] != 1) {
                found = false;
            }
        }
        if (!changed) {
            break;
        }
    }
    debug (ans);
    if (found) {
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
