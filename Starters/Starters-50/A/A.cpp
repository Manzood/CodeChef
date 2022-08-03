#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> ans;
    bool possible = true;
    if (x < n) {
        possible = false;
    } else if (x == n) {
        ans.resize(n);
        iota(ans.begin(), ans.end(), 1);
    } else {
        ans.push_back(x - n + 1);
        ans.push_back(1);
        int val = 2;
        while (val <= n) {
            if (val != x - n + 1)
                ans.push_back(val++);
            else
                val++;
        }
    }
    if (possible) {
        for (int i = 0; i < n; i++) {
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
