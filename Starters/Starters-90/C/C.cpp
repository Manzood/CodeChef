#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &m, &n);
    bool ans = n == m;
    int div = 2;
    int cur = m;
    while (cur % 2 == 0) {
        int val = m / div;
        if (n % val == 0)
            if (n / val <= div) ans = true;
        cur /= 2;
        div *= 2;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
