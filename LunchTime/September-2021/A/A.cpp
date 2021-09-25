#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        int mod = l % 3;
        if (mod > 0) l += 3 - mod;
        // debug (l);
        int ans = 0;
        if (l <= r) ans = 1;
        ans += (r - l) / 3;
        printf("%lld\n", ans);
    }
}
