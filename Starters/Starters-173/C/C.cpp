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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int mi = (int)1e7;
    int ind = -1;
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        if (b[i] < mi) {
            mi = b[i];
            ind = i;
        }
    }
    vector<int> c(m);
    int cur = ind;
    for (int i = 0; i < m; i++) {
        c[i] = b[cur];
        cur++;
        cur %= m;
    }
    /* debug(test, c); */
    bool changed = false;
    int last_replaced = -m - 1;
    for (int i = 0; i < n - m + 1; i++) {
        if (a[i] > c[0]) {
            changed = true;
        }
        if (changed && m > 1) {
            a[i] = c[0];
            last_replaced = i;
        } else if (a[i] > c[0]) {
            a[i] = c[0];
            last_replaced = i;
        }
    }
    /* debug(a); */
    if (last_replaced > -1) {
        for (int i = last_replaced; i < last_replaced + m; i++) {
            a[i] = c[i - last_replaced];
        }
    }
    bool replace = false;
    for (int i = n - m; i < n; i++) {
        if (a[i] == c[i - n + m]) continue;
        if (a[i] > c[i - n + m]) {
            replace = true;
            break;
        } else {
            break;
        }
    }
    /* debug(test, replace); */
    /* debug(a); */
    if (replace) {
        for (int i = n - m; i < n; i++) {
            a[i] = c[i - n + m];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
