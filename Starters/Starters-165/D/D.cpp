#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    bool found = false;
    for (int i = 0; i < n; i++)
        if (a[i] != 0) found = true;
    if (!found) {
        printf("0\n");
        return;
    }
    if (sum == 0) {
        printf("-1\n");
        return;
    }
    if (sum < 0) {
        for (int i = 0; i < n; i++) {
            a[i] = -a[i];
        }
        sum = -sum;
    }

    int pos = 0, neg = 0, ans = 0, nused = 0;
    for (int i = 0; i < n; i++) {
        if (sum < i + 1) {
            int diff = i + 1 - sum;
            int val = min(neg, diff);
            diff -= val, neg -= val;
            nused += val;
            if (a[0] < 0) a[0] += min(abs(a[0]), val);
            ans += val, sum += val;
            if (diff > 0) {
                pos += diff;
                a[0] += diff;
                ans += diff;
                sum += diff;
            }
        }
        if (a[i] < 0)
            neg += -a[i];
        else
            pos += a[i];
    }

    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    assert(s + nused >= n);

    sum += neg, ans += neg;
    if (a[0] < 0) a[0] = 0;

    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > 0) {
            sum -= a[i], ans += a[i];
            if (sum < i) {
                int diff = i - sum;
                sum += diff, a[0] += diff, ans += diff;
            }
        }
    }
    ans += a[0];
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
