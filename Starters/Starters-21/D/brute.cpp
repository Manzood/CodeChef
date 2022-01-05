#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort (a.begin(), a.end());
    int ans = 0;
    // while the median is less than the mean, increase it
    int ind = n / 2;
    if (n % 2 == 0) ind--;
    // debug (n);
    // int cnt = 1;
    while (a[ind] * n < sum) {
        a[ind]++;
        sum++;
        ans++;
        sort (a.begin(), a.end());
    }
    while (sum < a[ind] * n) {
        sum++;
        a[n-1]++;
        ans++;
    }
    // debug (a);
    printf("%lld\n", ans);
}

int32_t main () {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
