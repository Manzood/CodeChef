#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int c (int num, int pow) {
    return (num ^ (pow - 1));
}

int ans = 0;
int get(int n) {
    if (n == 1) return 0;
    // if (n == 2) {
    //     ans += 6;
    //     return 0;
    // }
    int retval = 0;
    int pow = 1;
    while (pow <= n) pow *= 2;
    int cnt = 0;
    if (n == pow - 1) n--;
    for (int i = n; i >= pow / 2; i--) {
        ans += (i ^ c(i, pow)) * 2;
        // cerr << i << " " << c(i, pow) << endl;
        cnt++;
    }
    retval = (pow / 2 - 1) - cnt;
    return retval;
}

void solve() {
    ans = 0;
    int n;
    scanf("%lld", &n);
    while (n > 0) {
        // debug (n);
        n = get(n);
        // debug (n);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
