#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> ans;
    if (n % 2 == 1) {
        for (int i = 0; i < n / 2; i++) {
            ans.push_back (i + 1);
        }
        ans.push_back (n);
        for (int i = n - 1; i >= n / 2; i--) {
            ans.push_back (i);
        }
    } else {
        for (int i = n / 2 + 1; i <= n; i++) {
            ans.push_back (i);
        }
        for (int i = n / 2 - 1; i >= 1; i--) {
            ans.push_back (i);
        }
        ans.push_back (n / 2);
    }
    if (n == 2) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
