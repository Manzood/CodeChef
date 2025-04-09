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
    int zeroes = 0, ones = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            zeroes++;
        else
            ones++;
        if (zeroes == ones) ans *= 2;
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
