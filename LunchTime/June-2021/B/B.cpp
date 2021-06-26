#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        int odd = -1;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (odd == -1 && a[i] % 2 == 1) odd = i;
        }
        vector <int> ans;
        for (int i = 0; i < n; i++) {
            if (i != odd) {
                ans.push_back (a[i]);
            }
        }
        if (odd >= 0) ans.push_back (a[odd]);
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
