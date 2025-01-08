#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool alternating(string& s) {
    int n = (int)s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool found = false;
            string cur = s.substr(i, j - i + 1);
            // find each substring inside this, reverse it
            for (int x = i; x <= j; x++) {
                for (int y = x; y <= j; y++) {
                    reverse(cur.begin() + x - i, cur.begin() + y - i + 1);
                    if (alternating(cur)) found = true;
                    reverse(cur.begin() + x - i, cur.begin() + y - i + 1);
                }
            }
            ans += found;
            // if (found) {
            //     debug(i, j);
            // }
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
