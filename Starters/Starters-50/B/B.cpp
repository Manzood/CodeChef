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
    vector<int> ans;
    ans.push_back(n);
    ans.push_back(n - 2);
    for (int i = 1; i < n - 3; i++) {
        ans.push_back(i);
    }
    ans.push_back(n - 3);
    ans.push_back(n - 1);
    if (n == 3) ans = {3, 2, 1};
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
