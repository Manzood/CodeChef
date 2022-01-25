#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%lld", &x);
        int it = lower_bound (a.begin(), a.end(), x) - a.begin();
        int val = 1;
        if (a[it] == x) {
            val = 0;
        } else {
            int cnt = n - it;
            if (cnt % 2 == 1) val = -1;
        }
        if (val == 1) {
            printf("POSITIVE\n");
        } else if (val == 0) {
            printf("0\n");
        } else {
            printf("NEGATIVE\n");
        }
    }
}
