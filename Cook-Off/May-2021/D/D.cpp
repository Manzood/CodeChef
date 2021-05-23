#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        // it has to be k-repeating
        int ans = 0;
        for (int i = 0; i < k; i++) {
            map <int, int> mp;
            int mx = 0;
            int cnt = 0;
            for (int j = i; j < n; j += k) {
                mp[a[j]]++;
                mx = max (mp[a[j]], mx);
                cnt++;
            }
            ans += cnt - mx;
        }
        printf("%lld\n", ans);
    }
}
