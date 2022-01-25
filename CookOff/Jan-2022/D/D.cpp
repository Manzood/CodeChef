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
    vector <int> ans = {1};
    int val = 1;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            val++;
        } else {
            val += 3;
        }
        ans.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
