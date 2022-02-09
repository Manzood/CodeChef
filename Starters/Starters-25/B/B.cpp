#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(2 * n);
    vector <int> cnt(n + 2, 0);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            break;
        }
        if (cnt[i] == 1) {
            possible = false;
        }
    }
    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
