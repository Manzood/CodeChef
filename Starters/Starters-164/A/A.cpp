#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    vector<int> a(n);
    set<int> s;
    bool repeat = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (s.count(a[i])) {
            repeat = true;
        }
        s.insert(a[i]);
    }
    if (repeat) {
        printf(l == 0 ? "YES\n" : "NO\n");
        return;
    }
    if (n > 1000) {
        printf("NO\n");
    } else {
        int val = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                val *= (a[i] ^ a[j]);
                if (val > r) break;
            }
        }
        if (val < l || val > r) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
