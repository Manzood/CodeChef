#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        vector <pair <int, int>> b(n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i].first);
            b[i].second = i;
        }

        sort (b.begin(), b.end());
        int mex = 0;

        for (int i = 0; i < n; i++) {
            // for each b[i], make sure to pick a remainder that hasn't already been picked yet
            if (b[i].first - 1 > mex) {
                a[b[i].second] = ++mex + b[i].first;
            } else {
                a[b[i].second] = b[i].first;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%lld ", a[i]);
        }
        printf("\n");
    }
}
