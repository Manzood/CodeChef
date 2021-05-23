#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int getval (int x, int y) {
    int cur = 1;
    int ret = 0;
    for (int i = 0; i < y; i++) {
        ret += cur;
        cur++;
    }
    cur--;
    for (int i = 1; i < x; i++) {
        ret += cur;
        cur++;
    }
    return ret;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        swap (x1, y1);
        swap (x2, y2);
        // printf("%lld %lld", getval (x1, y1), getval (x2, y2));
        int cur = getval (x1, y1);
        int ans = 0;
        for (int i = y1; i < y2; i++) {
            ans += cur;
            int incr = i + 1 + x1 - 1;
            cur += incr;
            // debug (cur);
        }
        for (int i = x1; i < x2; i++) {
            ans += cur;
            int incr = i + y2 - 1;
            cur += incr;
            // debug (cur);
        }
        ans += cur;
        printf("%lld\n", ans);
    }
}
