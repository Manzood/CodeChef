#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        int d = y - x;
        int ans;
        if (d >= 0) {
            ans = d / 2;
            if (d % 2 == 1) ans += 2;
        } else {
            ans = -d;
        }
        printf("%lld\n", ans);
    }
}
