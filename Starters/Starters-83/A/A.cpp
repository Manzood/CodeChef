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
    char cur = ' ';
    int occ = 0;
    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == cur) {
            occ++;
        } else {
            if (occ > 0) {
                ans += cur;
                occ--;
                if (occ & 1) ans += cur;
            }
            occ = 1;
            cur = s[i];
        }
    }
    if (occ > 0) {
        ans += cur;
        occ--;
        if (occ & 1) ans += cur;
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
