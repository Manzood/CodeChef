#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    int lastind = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum <= k) {
            lastind = i;
        } else {
            sum -= a[i];
            break;
        }
    }
    int ans = lastind + 1;
    // if (lastind < n - 1) {
    //     if (lastind > -1) {
    //         sum -= a[lastind];
    //         a[lastind] = (a[lastind] / 2) + (a[lastind] & 1);
    //         sum += a[lastind];
    //         sum += a[lastind + 1];
    //     } else {
    //         sum = 0;
    //         a[0] = (a[0] / 2) + (a[0] & 1);
    //         sum = a[0];
    //     }
    //     if (sum <= k) {
    //         ans++;
    //     }
    // }
    if (lastind < n - 1) {
        lastind++;
        a[lastind] = (a[lastind] / 2) + (a[lastind] & 1);
        sum += a[lastind];
        if (sum <= k) ans++;
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
