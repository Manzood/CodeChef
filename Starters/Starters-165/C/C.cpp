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
    vector<int> best(n, 1);
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            best[i] = best[i - 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int evenCnt = 0, val2 = 0;
        int ind = i - best[i] + 1;
        if (ind > 0) {
            if (best[ind - 1] % 2 == 0) {
                evenCnt = best[ind - 1] / 2;
                ind = ind - best[ind - 1];
                if (ind > 0) ind = ind - best[ind - 1];
                if (best[i] % 2 == 0) val2 = evenCnt;
            } else {
                if (best[i] % 2 == 0)
                    val2 = best[ind - 1];
                else
                    val2 = best[ind - 1] / 2;
            }
        }
        int val = i - ind + 1 - evenCnt;
        // debug(i, ind, val, val2);
        ans += val + val2;
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
