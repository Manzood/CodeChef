#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    vector<int> bits(30, 0);
    for (int i = 0; i < 30; i++) {
        if (((1LL << i) & a) != ((1LL << i) & b)) {
            bits[i] = ((1LL << i) & a) ? 1 : 2;
        }
    }
    int ans = 0;
    bool found = false;
    for (int i = 29; i >= 0; i--) {
        if (bits[i] > 0) {
            if (!found) {
                if (bits[i] == 2) ans |= (1LL << i);
            } else {
                if (bits[i] == 1) ans |= (1LL << i);
            }
            found = true;
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
