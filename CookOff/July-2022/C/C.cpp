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
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &l[i], &r[i]);
    }
    // at most two possible thieves
    int maxleft = -1;
    int leftind = -1;
    for (int i = 0; i < n; i++) {
        if (l[i] > maxleft) {
            maxleft = l[i];
            leftind = i;
        } else if (l[i] == maxleft) {
            leftind = -1;
        }
    }
    int minright = (int)1e9 + 7;
    int rightind = -1;
    for (int i = 0; i < n; i++) {
        if (r[i] < minright) {
            minright = r[i];
            rightind = i;
        } else if (r[i] == minright) {
            rightind = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == leftind) continue;
        if (l[i] > leftind + 1 || r[i] < leftind + 1) leftind = -1;
    }
    for (int i = 0; i < n; i++) {
        if (i == rightind) continue;
        if (l[i] > rightind + 1 || r[i] < rightind + 1) rightind = -1;
    }
    if (l[leftind] <= leftind + 1 && r[leftind] >= leftind + 1) leftind = -1;
    if (l[rightind] <= rightind + 1 && r[rightind] >= rightind + 1)
        rightind = -1;
    set<int> ans;
    if (leftind > -1) {
        ans.insert(leftind);
    }
    if (rightind > -1) {
        ans.insert(rightind);
    }
    printf("%lld\n", (int)ans.size());
    assert((int)ans.size() < 3 && (int)ans.size() > 0);
    for (auto x : ans) {
        printf("%lld\n", x + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
