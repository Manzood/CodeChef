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
        bool possible = true;
        if (n % 4 != 0) possible = false;
        if (possible) {
            printf("YES\n");
            vector <int> a, b;
            for (int i = 1; i <= n; i++) {
                if (i % 4 == 1 || i % 4 == 0) {
                    a.push_back(i);
                } else {
                    b.push_back(i);
                }
            }
            reverse(a.begin(), a.end());
            for (int i = 0; i < n / 2; i++) {
                printf("%lld ", a[i]);
            }
            printf("\n");
            for (int i = 0; i < n / 2; i++) {
                printf("%lld ", b[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
}
