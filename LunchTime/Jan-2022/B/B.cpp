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
    string s, t;
    cin >> s;
    t = s;
    int m = s[0] == '0' ? 0 : 10 - (s[0] - '0');
    int ans = 0;
    if (k >= m) ans = 1;
    vector <int> moves(n, 0);
    for (int i = 1; i < n; i++) {
        moves[i] += moves[i-1];
        if (s[i] >= s[i-1]) {
            moves[i] += s[i] - s[i-1];
        } else {
            moves[i] += 10 - (s[i-1] - '0');
            moves[i] += s[i] - '0';
        }
        int cur = 0;
        if (s[i] > '0') {
            cur = 10 - (s[i] - '0');
        }
        if (moves[i] + cur <= k) {
            ans = i + 1;
        } else {
            break;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
