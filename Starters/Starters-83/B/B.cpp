#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    int x = 0;
    bool afound = false, bfound = false;
    for (int i = 1; i >= 0; i--) {
        if ((c ^ x) <= (a ^ x) || (c ^ x) <= (b ^ x)) {
            if (((c ^ x) & (1LL << i)) == 0) {
                x |= (1LL << i);
                if (((b ^ x) & (1LL << i)) == 0) {
                    bfound = true;
                }
                if (((a ^ x) & (1LL << i)) == 0) {
                    afound = true;
                }
            }
        } else {
            if ((((c ^ x) & (1LL << i)) == 0) && (b ^ x) < (a ^ x)) {
                x = -1;
                break;
            } else {
                if (((b ^ x) & (1LL << i)) == 0) {
                    if ((bfound && afound) || ((c ^ x) & (1LL << i)) == 0) {
                        x |= (1LL << i);
                    }
                }
            }
        }
    }
    if ((c ^ x) <= (a ^ x) || (c ^ x) <= (b ^ x) || (b ^ x) <= (a ^ x)) x = -1;
    printf("%lld\n", x);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
