#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int s1 = 0, s2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = n - 2; i >= 0; i--) {
        s2 += a[i];
    }
    s1 = a[n-1];
    cnt1 = 1;
    cnt2 = n - 1;
    float mean1 = (float) s1 / cnt1;
    float mean2 = (float) s2 / cnt2;
    printf("%f\n", mean1 + mean2);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
