#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<vector<int>> b = a, c = a, d = a;
    int sub = 0;
    for (int i = 0; i < n; i++) {
        int tmp = sub;
        for (int j = 0; j < m; j++) {
            a[i][j] -= tmp;
            b[i][j] += tmp;
            tmp++;
        }
        sub++;
    }
    sub = 0;
    for (int i = 0; i < n; i++) {
        int tmp = sub;
        for (int j = 0; j < m; j++) {
            c[i][j] -= tmp;
            tmp++;
        }
        sub--;
    }
    sub = 0;
    for (int i = 0; i < n; i++) {
        int tmp = sub;
        for (int j = 0; j < m; j++) {
            d[i][j] -= tmp;
            tmp--;
        }
        sub++;
    }
    map<int, int> mp1, mp2, mp3, mp4;
    int ans = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mp1[a[i][j]]++;
            mp2[b[i][j]]++;
            mp3[c[i][j]]++;
            mp4[d[i][j]]++;
            ans = min(ans, n * m - mp1[a[i][j]]);
            ans = min(ans, n * m - mp2[b[i][j]]);
            ans = min(ans, n * m - mp3[c[i][j]]);
            ans = min(ans, n * m - mp4[d[i][j]]);
        }
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
