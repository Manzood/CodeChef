#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e, h, a, b, c;
        scanf("%lld%lld%lld%lld%lld%lld", &n, &e, &h, &a, &b, &c);
        // pair where first is cost, second is number of eggs left
        vector <vector <int>> dp[n];
        for (int i = 0; i < n; i++) {
            dp[i].resize(3);
            if (i == 0) {
                dp[i][0] = {a, e - 2, h};
                dp[i][1] = {b, e, h - 3};
                dp[i][2] = {c, e - 1, h - 1};
            } else {

            }
        }
    }
}
