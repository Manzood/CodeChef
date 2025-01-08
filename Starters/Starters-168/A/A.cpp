#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k, x;
    scanf("%lld%lld%lld", &n, &x, &k);
    string s;
    cin >> s;
    int ans = 2;
    int inversions = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            inversions += ones;
        } else {
            ones++;
        }
    }
    if (inversions <= x && inversions % k == 0) {
        ans = 1;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
