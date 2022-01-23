#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    string s = "abc";
    string ans = "";
    int len = 0;
    while (n - len > 3) {
        ans += s;
        len += 3;
    }
    n -= len;
    for (int i = 0; i < n; i++) {
        ans += s[i];
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
