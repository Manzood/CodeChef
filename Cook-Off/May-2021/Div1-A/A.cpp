#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        if (y % x != 0) {
            printf("-1\n");
        } else {
            int n = y / x;
            int ans = 0;
            int num = 1;
            int cnt = 1;
            while ((2 * num - 1) <= n) {
                num *= 2;
                cnt++;
            }
            if (num > 1) num--;
            while (num >= 1) {
                if (num <= n) {
                    n -= num;
                    ans += cnt;
                }
                num++;
                num /= 2;
                num--;
                cnt--;
            }
            if (n > 0) ans = 0;
            printf("%lld\n", ans - 1);
        }
    }
}
