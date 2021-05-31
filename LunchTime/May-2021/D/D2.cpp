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
        // find maximum subarray
        vector <int> mx(n, -inf);
        vector <int> mx2(n, -inf);
        int ans = -1e9;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
            ans = max (sum, ans);
            if (sum < 0) sum = 0;
            mx[i] = ans;
            // printf("%lld ", mx[i]);
        }
        // printf("\n");
        sum = 0;
        ans = -1e9;
        for (int i = n - 1; i >= 0; i--) {
            sum += a[i];
            ans = max (sum, ans);
            if (sum < 0) sum = 0;
            mx2[i] = ans;
        }
        if (k == 1) {
            printf("%lld\n", mx[n-1]);
        } else {
            ans = -1e9;
            for (int i = 0; i < n; i++) {
                if (i < n - 1) ans = max (mx[i] + 2 * mx2[i + 1], ans);
            }
            printf("%lld\n", ans);
        }
    }
}
