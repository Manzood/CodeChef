#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    for (int i = 3; i <= 100; i++) {
        int val = i;
        bool found = false;
        int second = 1000;
        debug(val);
        while (!found) {
            if (__gcd(val, second) > 1 && __gcd(val, second + 1) > 1) {
                debug(val, second, second + 1);
                found = true;
            }
            if (second >= (int)1e7) {
                debug(val, "not found");
                found = true;
            }
            second++;
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
