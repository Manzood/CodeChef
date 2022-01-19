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
    for (int i = 0; i < n && (int) ans.size() < n; i++) {
        for (int j = i + 1; j < 20 && (int) ans.size() < n; j++) {
            for (int k = j + 1; k < 20 && (int) ans.size() < n; k++) {
                for (int x = k + 1; x < 20 && (int) ans.size() < n; x++) {
                    int val = (1LL << i) + (1LL << j) + (1LL << k) + (1LL << x);
                    ans.push_back (val);
                }
            }
        }
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
