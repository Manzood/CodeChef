#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> getNGE(vector<int> a) {
    int n = (int)a.size();
    vector<int> nge(n, -1);
    stack<pair<int, int>> s;
    s.push({a[0], 0});
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push({a[i], i});
            continue;
        }
        while (s.empty() == false && s.top().first <= a[i]) {
            nge[s.top().second] = a[i];
            s.pop();
        }
        s.push({a[i], i});
    }
    return nge;
}

vector<int> getNSE(vector<int> a) {
    int n = (int)a.size();
    vector<int> nse(n, -1);
    stack<pair<int, int>> s;
    s.push({a[0], 0});
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push({a[i], i});
            continue;
        }
        while (s.empty() == false && s.top().first >= a[i]) {
            nse[s.top().second] = a[i];
            s.pop();
        }
        s.push({a[i], i});
    }
    return nse;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> cpy = a;
    reverse(cpy.begin(), cpy.end());
    vector<int> nge = getNGE(a);
    vector<int> pge = getNGE(cpy);
    // vector<int> pse = getNSE(cpy);
    reverse(pge.begin(), pge.end());
    // reverse(pse.begin(), pse.end());
    set<int> s;
    for (int i = 0; i < n; i++) {
        int p = pge[i];
        if (p != -1) {
            s.insert(abs(a[i] - p));
        }
        p = nge[i];
        if (p != -1) {
            s.insert(abs(a[i] - p));
        }
    }
    printf("%lld\n", (int)s.size());
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
