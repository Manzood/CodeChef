#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, p;
    scanf("%lld %lld", &n, &p);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort (a.begin(), a.end());
    int ansk = 0;
    int ansc = 0;

    for (int k = 1; k <= n; k++) {
        int c = 0;
        for (int i = 0; i < k; i++) {
            c += a[i] + (i + 1) * k;
        }

        if (c <= p) {
            ansk = k;
            ansc = c;
        }
    }

    printf("%lld %lld\n", ansk, ansc);
}

