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
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%lld", &a[i]);
    }
    map<int, int> cnt;
    int lim = n / 2;
    bool ans = true;
    for (int i = 0; i < 2 * n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > (2 * n - lim)) ans = false;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
