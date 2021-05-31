#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int inf = 1e9 + 7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        vector <vector <int>> dp(n, vector <int> (k, -inf));
        vector <int> mx (k, -inf);
        for (int i = 0; i < n; i++) {
            scanf("%lld\n", &a[i]);
            for (int j = 0; j < k; j++) {
                if (i >= j) {
                    if (j == 0) dp[i][j] = a[i] * (j + 1);
                    if (i > 0) dp[i][j] = max (dp[i-1][j] + a[i] * (j + 1), dp[i][j]);
                    // if (i > 0) dp[i][j] = max (dp[i-1][j], dp[i][j]);
                    if (j > 0 && i > 0) dp[i][j] = max (mx[j-1] + a[i] * (j + 1), dp[i][j]);
                    // mx[j] = max (mx[j], dp[i][j]);
                }
            }
            for (int j = 0; j < k; j++) mx[j] = max (mx[j], dp[i][j]);
        }
        // printf("Printing\n");
        // for (int i = 0; i < n; i++) {
            // for (int j = 0; j < k; j++) {
                // printf("%lld ", dp[i][j]);
            // }
            // printf("\n");
        // }
        int ans = -inf;
        for (int i = 0; i < n; i++) {
            ans = max (dp[i][k-1], ans);
        }
        printf("%lld\n", ans);
    }
}
