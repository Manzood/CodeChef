#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, h, x;
    scanf("%lld%lld%lld", &n, &h, &x);
    vector <int> a(n);
    bool ans = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] + x >= h) ans = true;
    }
    printf(ans ? "YES\n" : "NO\n");
}
