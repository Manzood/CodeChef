#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a((1LL << n));
        // debug (n);
        // debug ((1LL << n));
        for (int i = 0; i < (1LL << n); i++) {
            scanf("%lld", &a[i]);
        }
        sort (a.begin(), a.end());
        bool possible = true;
        if (a[(1LL << n) - 1] - a[0] > 1) {
            possible = false;
        }
        printf(possible ? "YES\n" : "NO\n");
    }
}
