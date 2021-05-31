#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, K;
        scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &K);
        int dist = abs (a - c);
        dist += abs (b - d);
        bool ans = true;
        if (dist > K) ans = false;
        else {
            if ((K - dist) % 2 == 1) ans = false;
        }
        ans ? printf("YES\n") : printf("NO\n");
    }
}
