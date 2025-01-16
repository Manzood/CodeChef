#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = 62;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        int mask = (1LL << MX) - 1LL;
        mask--;
        bool possible = true;
        for (int j = i + 1; j < i + MX && j < n; j++) {
            int v1 = a[j] & mask;
            int v2 = a[i] & mask;
            if (i == 0) debug(j, v1, v2);
            if (v1 != v2) {
                possible = false;
                break;
            }
            ans++;
            mask = mask ^ (1LL << (j - i));
        }
        if (possible) {
            int rem = max(0LL, n - (i + MX));
            ans += rem;
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
