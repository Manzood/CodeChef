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
    int ones = 0, zeroes = 0;
    for (int i = 0; i < n; i++) {
        ones += s[i] == '1';
        zeroes += s[i] == '0';
    }
    int moves = min(ones, zeroes);
    if (moves & 1) {
        printf("Zlatan\n");
    } else {
        printf("Ramos\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
