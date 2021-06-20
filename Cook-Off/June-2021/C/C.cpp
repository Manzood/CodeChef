#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
            }
        }
        if (cnt == 0) {
            printf("1\n");
        } else if (cnt == n) {
            printf("0\n");
        } else if (cnt == 1) {
            printf("0\n");
        } else {
            int ans = 1e9+7;
            // factorise n
            // vector <int> factors;
            // for (int i = 2; i * i <= n; i++) {
                // if (n % i == 0) {
                    // factors.push_back (i);
                    // factors.push_back (n / i);
                // }
            // }
            // for (auto x: factors) {
            for (int x = 1; x <= n; x++) {
                if (n % x == 0) {
                    for (int i = 0; i < n / x; i++) {
                        int c = 0;
                        int tot = 0;
                        for (int j = i; j < n; j += x) {
                            if (s[j] == '1') c++;
                            tot++;
                        }
                        int diff = cnt - c;
                        ans = min (diff + tot - c, ans);
                    }
                }
            }
            // }
            printf("%lld\n", ans);
        }
    }
}

