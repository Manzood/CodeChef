#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector <int> cnt(64, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1LL << j)) {
                cnt[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (cnt[i] >= 2) {
            ans += (1LL << i);
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
