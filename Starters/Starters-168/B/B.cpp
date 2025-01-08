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
    map<int, int> till;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (!s.count(a[i])) {
            s.insert(a[i]);
        } else {
            till[a[i]] = i;
        }
    }
    int ans = 0;
    int right = -1, start = -1;
    for (int i = 0; i < n; i++) {
        if (till.count(a[i])) {
            if (i > right) {
                set<int> cur;
                if (start > -1) {
                    for (int j = start; j <= right; j++) {
                        cur.insert(a[j]);
                    }
                }
                ans += (int)cur.size();
                start = i;
            }
            right = max(right, till[a[i]]);
        }
    }
    set<int> cur;
    for (int i = start; i <= right && i >= 0; i++) {
        cur.insert(a[i]);
    }
    ans += (int)cur.size();
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
