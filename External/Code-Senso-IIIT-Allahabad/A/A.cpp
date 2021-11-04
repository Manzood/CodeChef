#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        vector <int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                ans[i] = max (ans[i], a[i] & a[i+1]);
            }
            if (i > 0) {
                ans[i] = max (ans[i], a[i] & a[i-1]);
            }
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
