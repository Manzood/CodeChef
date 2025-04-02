#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool compare(vector<int> a, vector<int> b, int ind) {
    /* debug(a, b, ind); */
    for (int i = ind; i < (int)ind + (int)b.size(); i++) {
        if (a[i] > b[i - ind])
            return true;
        else if (a[i] < b[i - ind])
            return false;
    }
    /* debug(a, b, ind); */
    return false;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    for (int ind = 0; ind < m; ind++) {
        vector<int> cur(m);
        int x = ind;
        for (int i = 0; i < m; i++) {
            cur[i] = b[x];
            x++;
            x %= m;
        }
        for (int i = 0; i < n - m + 1; i++) {
            if (compare(a, cur, i)) {
                for (int j = i; j < i + m; j++) {
                    a[j] = cur[j - i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
