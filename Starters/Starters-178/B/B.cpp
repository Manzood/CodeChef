#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<int>& a) {
    int n = (int)a.size();
    if (n == 0) return true;
    vector<int> tmp;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) return false;
        tmp.push_back(a[i] - a[i - 1]);
    }
    return check(tmp);
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    string s(n, '0');
    if (n > 32) {
        cout << s << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            tmp.push_back(a[j]);
        }
        if (check(tmp)) s[i] = '1';
    }
    cout << s << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
