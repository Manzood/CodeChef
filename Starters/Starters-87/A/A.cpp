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
    int a = 1, b = 1, c = 0;
    if (n == 1) {
        printf("-1\n");
        return;
    }
    if (n > (int)1e6 + 1) {
        a = n / (int)1e6;
        b = (int)1e6;
        c = n % b;
        if (c == 0) {
            c = b;
            a--;
        }
    } else {
        c = n - 1;
    }
    assert(a * b + c == n);
    printf("%lld %lld %lld\n", a, b, c);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
