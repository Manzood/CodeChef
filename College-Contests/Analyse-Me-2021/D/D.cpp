#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, p;
    scanf("%lld%lld", &n, &p);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // you can pick at most 1000 items?
    int ansk = 0;
    int ansc = 0;

    int k = min(1500LL, n);

    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += a[i] + (i + 1) * k;
    }

    while (cost > p) {
        // get rid of one item
        vector <int> items(n);
        for (int i = 0; i < n; i++) {
            items[i] = a[i] + (i + 1) * (k - 1);
        }
        sort (items.begin(), items.end());
        cost = 0;
        for (int i = 0; i < k - 1; i++) {
            cost += items[i];
        }
        k--;
    }

    ansk = k;
    ansc = cost;

    printf("%lld %lld\n", ansk, ansc);
}
