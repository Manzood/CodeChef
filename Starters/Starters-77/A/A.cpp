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
    string a, b;
    cin >> a >> b;
    if (n > m) {
        swap(n, m);
        swap(a, b);
    }
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < n; i++) {
        cnt1[a[i] - 'a']++;
    }
    for (int i = 0; i < m; i++) {
        cnt2[b[i] - 'a']++;
    }
    bool ans = true;
    for (int i = 0; i < 26; i++) {
        cnt2[i] -= cnt1[i];
        if (cnt2[i] < 0) ans = false;
    }
    int len = m - n;
    int odd = len & 1;
    for (int i = 0; i < 26; i++) {
        if (cnt2[i] & 1) {
            if (!odd)
                ans = false;
            else
                odd--;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
