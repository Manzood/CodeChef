#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<int>& pos, vector<int>& neg, int val) {
    int ptr = 0, cur = 0;
    for (int i = 0; i < (int)pos.size(); i++) {
        if (pos[i] > val) return false;
        while (cur + pos[i] > val && ptr < (int)neg.size()) {
            cur += neg[ptr++];
        }
        if (cur < 0) cur = 0;
        cur += pos[i];
        if (cur > val) return false;
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), pos, neg;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] >= 0) {
            pos.push_back(a[i]);
            sum += a[i];
        } else {
            neg.push_back(a[i]);
        }
    }
    int low = 0, high = sum, ans = sum;
    while (low < high) {
        int val = (low + high) / 2;
        if (check(pos, neg, val)) {
            ans = val;
            high = val;
        } else {
            low = val + 1;
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
