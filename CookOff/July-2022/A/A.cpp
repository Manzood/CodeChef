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
    vector<int> ans = {3, 4, 1, 2};
    for (int i = 5; i <= n; i++) {
        ans.push_back(i);
    }
    if (n > 3) {
        for (int i = 0; i < n; i++) {
            // if (i < n - 2) {
            // assert((ans[i] ^ ans[i + 1]) != ans[i + 2]);
            // }
            printf("%lld ", ans[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
