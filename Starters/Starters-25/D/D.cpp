#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int diff = k - n;
    int num = 1;
    int val = 0;
    while ((num * (num - 1)) / 2 <= diff) {
        val = num;
        num++;
    }
    // debug (num)
    int cur = (val * (val - 1)) / 2;
    vector <int> ans(n, 1);
    int ind1 = n - val + 1;
    if (diff > cur) ind1--;
    int ind2 = ind1 + (diff - cur);
    if (ind2 == ind1) ind2 = n;
    int lastval = 1;
    // debug (ind1, ind2);
    for (int i = ind1; i < ind2; i++) {
        ans[i] = ++lastval;
    }
    for (int i = ind2 + 1; i < n; i++) {
        ans[i] = ++lastval;
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
