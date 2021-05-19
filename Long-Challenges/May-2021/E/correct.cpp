#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if ((m % j) % i == (m % i) % j) {
                    cnt++;
                    // printf("%lld %lld\n", i, j);
                }
            }
        }
        printf("%lld\n", cnt);
    }
}
