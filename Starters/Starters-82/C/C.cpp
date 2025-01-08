#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        b[i] = abs(b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    bool found = true;
    int target = a[0] + b[0];
    for (int i = 1; i < n; i++)
        if (a[i] + b[i] != target && a[i] - b[i] != target) found = false;
    ans += (int)found;
    found = true;
    target = a[0] - b[0];
    for (int i = 1; i < n; i++)
        if (a[i] + b[i] != target && a[i] - b[i] != target) found = false;
    ans += (int)found;
    reverse(b.begin(), b.end());
    found = true;
    target = a[0] + b[0];
    for (int i = 1; i < n; i++)
        if (a[i] + b[i] != target && a[i] - b[i] != target) found = false;
    ans += (int)found;
    found = true;
    target = a[0] - b[0];
    for (int i = 1; i < n; i++)
        if (a[i] + b[i] != target && a[i] - b[i] != target) found = false;
    ans += (int)found;
    if (b[0] == b[n - 1] && b[0] != 0)
        ans /= 4;
    else if (b[0] == b[n - 1])
        ans /= 2;
    map<int, int> cnt;
    for (auto x : b) {
        int val = ++cnt[x];
        ans *= val;
        ans %= MOD;
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
