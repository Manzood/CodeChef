#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int INF = 1e18;

vector <int> l, r;
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n+1, INF);
    d[0] = -INF;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            if (d[j] < INF) {
                cur = max(cur, j);
            }
        }
        l[i] = cur;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int lds(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n+2, -INF);
    d[n + 1] = INF;

    int cur = n + 1;
    for (int i = n - 1; i >= 0; i--) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin() - 1;
        if (j < 0) j++;
        if (d[j+1] > a[i] && a[i] > d[j]) {
            d[j] = a[i];
            if (d[j] > -INF) {
                cur = min(cur, j);
            }
        }
        r[i] = n - cur + 1;
    }

    int ans = 0;
    for (int i = n; i >= 0; i--) {
        if (d[i] > -INF && d[i] < INF)
            ans = n - i + 1;
    }
    return ans;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    r.resize(n, INF);
    l.resize(n, INF);
    // r.assign(n, INF);
    // l.assign(n, INF);
    lis(a);
    lds(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int leftval = 0;
        if (i > 0) leftval = l[i-1];
        ans = max(ans, leftval + r[i]);
    }
    ans = max(ans, l[n-1]);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
