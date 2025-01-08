#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> a(n);
    vector<bool> good(30, false), on(30, false), off(30, false);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1LL << j))
                on[j] = true;
            else
                off[j] = true;
        }
    }
    int smallest = -1;
    bool found = false;
    for (int i = 0; i < 30; i++) {
        if (on[i] && off[i]) {
            if (!(x & (1LL << i))) found = true;
            if (smallest == -1) smallest = i;
        }
    }
    int ans = x;
    if (!found) {
        ans -= (1LL << smallest);
        for (int i = 0; i < smallest; i++) {
            ans |= (1LL << i);
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
