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
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a.begin(), a.end());
        int sz = a.size();
        int ans = a[sz-1] - a[sz-2] + a[sz-1] - a[0] + a[sz-2] -a[0];
        printf("%lld\n", ans);
    }
}
