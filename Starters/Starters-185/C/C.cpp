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
    vector<int> a(n);
    int threes = 0, othersum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 3) {
            threes++;
        } else {
            othersum += a[i];
        }
    }
    int ans = 0;
    if (othersum & 1) {
        if (threes == 1)
            ans = n - 1;
        else if (threes == 2)
            ans = n - 2;
        else
            ans = n;
    } else {
        if (threes <= 1)
            ans = threes;
        else
            ans = n;
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
