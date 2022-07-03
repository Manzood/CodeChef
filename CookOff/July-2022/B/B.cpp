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
    for (int i = 0; i < n / 2; i++) {
        ans.push_back(n - i);
        ans.push_back(i + 1);
    }
    if (n & 1) ans.push_back(n / 2 + 1);
    for (auto x : ans) {
        printf("%lld ", x);
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
