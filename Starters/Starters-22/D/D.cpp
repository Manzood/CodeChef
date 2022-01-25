#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...);
#endif

#define int long long
using namespace std;
constexpr int inf = 1e18;

void solve() {
    int n;
    scanf("%lld", &n);
    string a, b;
    cin >> a >> b;
    vector <vector <int>> dp(n, vector <int> (n + 1, inf));
    vector <vector <int>> ones(n, vector <int> (2, 0));
    vector <vector <int>> zeroes(n, vector <int> (2, 0));
    vector <vector <int>> mi(n, vector <int> (n + 1, inf));
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            ones[i][0] += ones[i-1][0];
            ones[i][1] += ones[i-1][1];
        }
        if (a[i] == '1') ones[i][0]++;
        if (b[i] == '1') ones[i][1]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            zeroes[i][0] += zeroes[i+1][0];
            zeroes[i][1] += zeroes[i+1][1];
        }
        if (a[i] == '0') zeroes[i][0]++;
        if (b[i] == '0') zeroes[i][1]++;
    }
    int inversions = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == '1') cnt++;
        else inversions += cnt;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            // consider the first j characters
            // first calculate current
            if (i > 0) {
                dp[i][j] = mi[i-1][j];
            } else {
                dp[i][j] = 0;
            }
            if (a[i] == '0') {
                dp[i][j] += ones[i][0];
                if (j > 0) dp[i][j] += ones[j-1][1];
            } else {
                // dp[i][j] += zeroes[i][0];
                if (j < n - 1) dp[i][j] += zeroes[j][1];
            }
            if (j > 0) mi[i][j] = min(dp[i][j], mi[i][j-1]);
            else mi[i][j] = dp[i][j];
        }
    }
    int ans = inf;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int j = 0; j <= n; j++) {
        ans = min (ans, dp[n-1][j]);
    }
    printf("%lld\n", ans + inversions);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}

