#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = 30;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    vector<pair<int, int>> x(MX);
    vector<int> cnt(MX, 0);
    for (int bit = 0; bit < MX; bit++) {
        pair<int, int> cur = {-1, n};
        for (int i = 0; i < n && ((1LL << bit) & a[i]) == 0; i++) {
            cur.first = i;
        }
        for (int i = n - 1; i >= 0 && ((1LL << bit) & b[i]); i--) {
            cur.second = i;
        }
        cur.first++;
        cur.second--;
        // cur.first represents the first index where A[i] turns on
        // cur.second represents the first index from the right where A[i] turns
        // off
        x[bit] = cur;
        cnt[bit] = n - cur.second - 1;
        if (cur.first < cur.second) {
            cnt[bit]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < MX; i++) {
        bool adding = false;
        if (cnt[i] & 1) {
            adding = true;
        } else {
            int rem = max(x[i].second - x[i].first - 1, 0LL);
            if (rem) adding = true;
        }
        if (adding) ans += (1LL << i);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
