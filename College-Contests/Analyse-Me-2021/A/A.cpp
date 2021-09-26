#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int aptr = 0, bptr = 0;
    int ans = 0;
    while (aptr < n && bptr < m) {
        if (abs (a[aptr] - b[bptr]) <= k) {
            // take apartment
            ans++;
            aptr++;
            bptr++;
        } else {
            if (a[aptr] < b[bptr]) {
                aptr++;
            } else {
                bptr++;
            }
        }
    }
    printf("%lld\n", ans);
}
