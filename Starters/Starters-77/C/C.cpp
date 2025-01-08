#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> diff;
    for (int i = 0; i < n / 2; i++) {
        if (abs(a[i] - a[n - i - 1]) > 0)
            diff.push_back(abs(a[i] - a[n - i - 1]));
    }
    sort(diff.begin(), diff.end());
    bool ans = false;
    ans |= ((int)diff.size() == 0);
    if (k < n) {
        k %= 2;
        if (k == 1) {
            ans = true;
        } else if (n & 1) {
            ans = true;
        } else {
            int f = 0, s = (int)diff.size() - 1;
            int sum = 0;
            for (auto x : diff) sum += x;
            ans |= (sum % 2 == 0);
            while (f < s) {
                int mi = min(diff[f], diff[s]);
                diff[f] -= mi;
                diff[s] -= mi;
                if (!diff[f]) f++;
                if (!diff[s]) s--;
            }
            bool found = false;
            for (auto x : diff) found |= (x != 0);
            ans |= !found;
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
