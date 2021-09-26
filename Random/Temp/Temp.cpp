#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
        if (m > n) swap (n, m);

        int ans = min ((n + m - 2) * x, (m - 1) * y + (n - m) * x);
        int ans2 = (m - 1) * y + (n - m) * y;
        if ((n - m) % 2 != 0) {
            ans2 += x;
            ans2 -= y;
        }
        ans = min (ans, ans2);

        printf("%lld\n", ans);
    }
}
