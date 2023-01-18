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
    vector<int> left(n + 2, 0), right(n + 2, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        left[a[i]]++;
    }
    int inv = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        inv += left[a[i] + 1];
        inv -= right[a[i] - 1];
        ans = max(ans, inv);
        left[a[i]]--;
        right[a[i]]++;
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
