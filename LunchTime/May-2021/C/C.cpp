#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int MAX_N = 1e7 + 10;

void sieve (vector <int>& is_prime, vector <int>& ans) {
    int n = is_prime.size() - 1;
    vector <int> pref (MAX_N, 0);
    int val = 1;
    int last = 0;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p] == true) {
            if (p > 2) {
                pref[p]++;
                pref[2 * p]--;
            }
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
        val += pref[p];
        ans[p] = val;
        last = p;
    }
    for (int i = last + 1; i <= n; i++) {
        if (is_prime[i]) {
            pref[i]++;
            if (2 * i <= n) pref[2 * i]--;
        }
        val += pref[i];
        ans[i] = val;
    }
}

int32_t main() {
    int t;
    cin >> t;
    vector <int> is_prime(MAX_N, true);
    vector <int> ans (MAX_N, 0);
    sieve (is_prime, ans);
    while (t--) {
        int n;
        scanf("%lld", &n);
        // printf("%lld\n", ans + 1);
        printf("%lld\n", ans[n]);
        // for (int i = 2; i <= n; i++) {
            // printf("%lld ", ans[i]);
        // }
        // printf("\n");
    }
}
