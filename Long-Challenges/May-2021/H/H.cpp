#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        scanf("%lld", &k);
        vector <int> A(2 * k + 1);
        int s = 0;
        for (int i = 0; i < 2 * k + 1; i++) {
            A[i] = k + (i + 1) * (i + 1);
            if (i > 0) {
                s += __gcd(A[i], A[i-1]);
            }
            // debug(A[i]);
        }
        printf("%lld\n", s);
    }
}
