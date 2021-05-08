#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int temp, a, b;
        scanf("%lld%lld%lld", &temp, &a, &b);
        int ans = a + (100 - temp) * b;
        printf("%lld\n", ans * 10);
    }
}
