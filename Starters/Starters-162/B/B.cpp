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
    string s;
    cin >> s;
    int x = 0, y = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            while (x < i && s[x] != 'B') x++;
            if (x == i)
                ans++;
            else
                x++;
        } else {
            while (y < i && s[y] != 'A') y++;
            if (y == i)
                ans++;
            else
                y++;
        }
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
