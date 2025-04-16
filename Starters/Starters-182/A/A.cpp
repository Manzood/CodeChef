#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 3;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt += a[i] > 0;
    }
    sort(a.begin(), a.end());
    if (cnt == 1) {
        printf("0\n");
        return;
    } else if (cnt == 2) {
        printf("%lld\n", a[1]);
        return;
    }
    int ans = 0;
    if (a[2] > a[1]) {
        ans = (a[0] % 2 == 1 && a[1] % 2 == 1) ? a[0] + a[1] - 1 : a[0] + a[1];
    } else {
        if (a[2] & 1) {
            ans = (a[0] % 2 == 1 && a[1] % 2 == 1) ? a[0] + a[1] - 1
                                                   : a[0] + a[1];
        } else {
            ans = a[0] + a[1];
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
