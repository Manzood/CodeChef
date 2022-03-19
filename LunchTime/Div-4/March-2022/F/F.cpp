#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int odd = 0;
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) odd++;
    }
    int rem = odd - 1;
    vector <int> b = a;
    a.resize(0);
    for (int i = 0; i < n; i++) {
        if ((b[i] & 1) == 0) a.push_back(b[i]);
    }
    for (int i = 0; i < n; i++) {
        if ((b[i] & 1) == 1) a.push_back(b[i]);
    }
    vector <int> ans;
    if ((rem & 1) == 0) {
        ans.push_back(a.back());
        for (int i = 0; i < n - 1; i++) {
            ans.push_back(a[i]);
        }
    } else {
        ans = a;
    }
    int sop = 0;
    for (int i = 1; i < n; i++) {
        sop += ans[i] * ans[i-1];
    }
    bool possible = sop & 1;
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
