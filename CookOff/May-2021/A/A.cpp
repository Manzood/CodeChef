#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int D, d, A, B, C;
        scanf("%lld%lld%lld%lld%lld", &D, &d, &A, &B, &C);
        int ans = 0;
        int val = D * d;
        if (val >= 10) ans = A;
        if (val >= 21) ans = B;
        if (val >= 42) ans = C;
        printf("%lld\n", ans);
    }
}
