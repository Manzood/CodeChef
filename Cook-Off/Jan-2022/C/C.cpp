#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int CeilIndex(std::vector<int>& v, int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int>& v) {
    if (v.size() == 0) return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] >= tail[length - 1])
            tail[length++] = v[i];
        else {
            int index = upper_bound(tail.begin(), tail.begin() + length, v[i]) - tail.begin();
            // tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
            // debug (index, v[i]);
            tail[index] = v[i];
            // debug (index);
        }
    }

    return length;
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    int lisa = LongestIncreasingSubsequenceLength(a);
    // debug ("found a")
    int lisb = LongestIncreasingSubsequenceLength(b);
    // debug (lisa, lisb);
    // debug (a, b, lisa, lisb);
    int ans = lisa + lisb;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
