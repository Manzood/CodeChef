#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

int getval(int num) {
    int val = 1;
    for (int i = 0; i < num; i++) {
        val *= 2;
        // val %= mod;
    }
    return val;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    vector<int> final(n, 0);
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        if (__gcd(a[i - 1], a[i]) > 1 ||
            (i < n - 1 && __gcd(a[i + 1], a[i]) > 1)) {
            int val = a[i];
            while ((__gcd(a[i - 1], val) > 1) ||
                   (i < n - 1 && __gcd(a[i + 1], val) > 1)) {
                val++;
            }
            int diff = val - a[i];
            final[i] = val;
            val = a[i];
            while ((__gcd(a[i - 1], val) > 1) ||
                   (i < n - 1 && __gcd(a[i + 1], val) > 1)) {
                val--;
            }
            if (diff < abs(val - a[i])) final[i] = val;
            diff = min(diff, abs(val - a[i]));
            // if (test == 2) debug(diff);
            dp[i][1] = dp[i - 1][0] + getval(diff);
            // dp[i][1] %= mod;
            dp[i][0] = dp[i - 1][1] + getval(diff);
            // dp[i][0] = mod;
        } else {
            // no changes necessary
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
            dp[i][0] = dp[i][1];
        }
    }
    // debug(dp);
    printf("%lld\n", min(dp[n - 1][0], dp[n - 1][1]));
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
