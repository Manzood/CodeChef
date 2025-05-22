#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    priority_queue<int, vector<int>, greater<int> > min_pq;
    int n;
    scanf("%lld", &n);
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 2 * n; i++) {
        if (i & 1) {
            if (a[i] > min_pq.top()) {
                min_pq.pop();
                min_pq.push(a[i]);
            }
        } else {
            min_pq.push(a[i]);
        }
    }
    int ans = 0;
    while (!min_pq.empty()) {
        ans += min_pq.top();
        min_pq.pop();
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
