#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    // find leftmost bit of a[n-1]
    int largest = 0;
    while ((1LL << (largest + 1) <= a[n-1])) largest++;
    int ind = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if ((1LL << largest) & a[i]) {
            ind = i;
        } else {
            break;
        }
    }
    // sliding window
    vector <int> bit_count(64, 0);
    int ans = 0;
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1LL << j)) {
                bit_count[j]++;
            }
        }
    }
    for (int i = 0; i < 32; i++) {
        if (bit_count[i] == k - 1) {
            ans += (1LL << i);
        }
    }
    for (int i = k - 1; i < ind; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i-k+1] & (1LL << j)) {
                bit_count[j]--;
            }
            if (a[i] & (1LL << j)) {
                bit_count[j]++;
            }
        }
        int val = 0;
        for (int j = 0; j < 32; j++) {
            if (bit_count[j] == k - 1) {
                val += (1LL << j);
            }
        }
        ans = max (val, ans);
    }

    int cur = 0;
    bit_count.assign(64, 0);
    while (cur + k - 1 < ind) cur++;
    for (int i = cur; i < k; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1LL << j)) {
                bit_count[j]++;
            }
        }
    }
    int val = 0;
    for (int i = 0; i < 32; i++) {
        if (bit_count[i] == k) {
            val += (1LL << i);
        }
        ans = max (val, ans);
    }
    for (int i = cur + k; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i-k] & (1LL << j)) {
                bit_count[j]--;
            }
            if (a[i] & (1LL << j)) {
                bit_count[j]++;
            }
        }
        val = 0;
        for (int j = 0; j < 32; j++) {
            if (bit_count[j] == k) {
                val += (1LL << j);
            }
        }
        ans = max (val, ans);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
