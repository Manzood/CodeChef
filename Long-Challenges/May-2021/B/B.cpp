#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, k;
        scanf("%lld%lld%lld", &n, &x, &k);
        bool ans = false;
        if (x % k == 0) ans = true;
        x = n + 1 - x;
        if (x % k == 0) ans = true;
        ans ? printf("YES\n") : printf("NO\n");
    }
}
