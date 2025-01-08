#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, h;
    scanf("%lld%lld", &n, &h);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int low = 0, high = (int)2e5;
    int x = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cur = h;
        for (int i = 0; i < n; i++) {
            if (mid < a[i]) {
                cur -= a[i];
            }
        }
        if (cur <= 0) {
            low = mid + 1;
        } else {
            x = mid;
            high = mid - 1;
        }
    }
    printf("%lld\n", x);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
