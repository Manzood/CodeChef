#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int g, p;
        scanf("%lld%lld", &g, &p);
        vector <int> x(10);
        for (int i = 0; i < 10; i++) {
            scanf("%lld", &x[i]);
        }
        int day = 0;
        int ans[2];
        int rem = 0;
        for (int i = 9; i >= g; i--) {
            x[i] -= rem;
            day += x[i] / p;
            x[i] = x[i] % p;
            if (x[i] > 0) day++;
            if (x[i] != 0) rem = p - x[i];
        }
        ans[0] = day;
        if (rem == 0) ans[0]++;
        x[g - 1] -= rem;
        day += x[g - 1] / p;
        x[g - 1] %= p;
        if (x[g - 1] > 0) day++;
        ans[1] = day;
        printf("%lld %lld\n", ans[0], ans[1]);
    }
}
