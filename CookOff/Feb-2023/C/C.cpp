#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MAXN = (int)1e6;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int ind, x;
            scanf("%lld%lld", &ind, &x);
            ind--;
            a[ind] = (x + 180) % 180;
        } else {
            int l, r;
            scanf("%lld%lld", &l, &r);
            l--;
            r--;
            vector<int> f(180, -1);
            f[a[l]] = l;
            int mi = 180;
            int x, y;
            for (int j = l; j <= r; j++) {
                if (f[a[j]] != -1) {
                    mi = 0;
                    x = f[a[j]];
                    y = j;
                    break;
                } else {
                    f[a[j]] = j;
                }
            }
        }
    }
}

int32_t main() {
    int tests = 1;
    // cin >> tests;
    for (int tt = 1; tt <= tests; tt++) {
        solve(tt);
    }
}
