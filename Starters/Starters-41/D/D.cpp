#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int inf = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = n;
    int l = 0;
    map <int, int> mp;
    for (int r = 0; r < n; r++) {
        mp[a[r]]++;
        while (mp[a[r]] > 1) {
            mp[a[l]]--;
            l++;
        }
        ans = min(ans, l + n - 1 - r + l);
        ans = min(ans, l + n - 1 - r + n - 1 - r);
        // if (test == 1) debug(l, r, ans);
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
