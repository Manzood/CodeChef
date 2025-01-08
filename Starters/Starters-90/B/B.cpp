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
    // check first
    bool can = false;
    string s;
    cin >> s;
    vector<int> occ(26, 0);
    for (int i = 0; i < n; i++) {
        occ[s[i] - 'a']++;
    }
    int cnt = 0;
    for (auto x : occ)
        if (x & 1) cnt++;
    if (cnt <= (n & 1)) {
        can = true;
    }
    if (!can) {
        printf("0\n");
        return;
    }
    int ans = 0;
    if (n & 1) {
        bool found = false;
        for (int x : occ)
            if (x % 2 == 0 && x > 0) found = true;
        ans = found ? 1 : 2;
    } else {
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
