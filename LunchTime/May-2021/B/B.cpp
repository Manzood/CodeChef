#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        string s;
        cin >> s;
        int dist = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                dist += 2;
            } else {
                dist += 1;
            }
        }
        for (int i = 0; i < k; i++) {
            int q;
            scanf("%lld", &q);
            q--;
            if (s[q] == '1') s[q] = '0';
            else s[q] = '1';
            if (q > 0) {
                if (s[q] == s[q-1]) {
                    dist += 1;
                } else {
                    dist -= 1;
                }
            }
            if (q < n - 1) {
                if (s[q] == s[q + 1]) {
                    dist += 1;
                } else {
                    dist -= 1;
                }
            }
            printf("%lld\n", dist);
        }
    }
}
