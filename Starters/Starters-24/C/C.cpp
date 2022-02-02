#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    bool possible = true;
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    if (n % 2 == 1) possible = false;
    sort (s.begin(), s.end());
    reverse (s.begin() + n / 2, s.end());
    for (int i = 0; i < n; i++) {
        if (s[i] == s[n-i-1]) possible = false;
    }
    if (possible) {
        printf("YES\n");
        cout << s << "\n";
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
