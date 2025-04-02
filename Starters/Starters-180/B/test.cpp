#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

string cur;
void get(int ind, int n, vector<string>& a) {
    if (ind == n) {
        bool found = true;
        for (int i = 1; i < n; i++) {
            if (cur[i] == cur[i - 1]) {
                found = false;
            }
        }
        if (found) a.push_back(cur);
        return;
    }
    cur += 'A';
    get(ind + 1, n, a);
    cur.pop_back();
    cur += 'B';
    get(ind + 1, n, a);
    cur.pop_back();
    cur += 'C';
    get(ind + 1, n, a);
    cur.pop_back();
}

int lcs(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), current(m + 1, 0);
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                current[ind2] = 1 + prev[ind2 - 1];
            else
                current[ind2] = max(prev[ind2], current[ind2 - 1]);
        }
        prev = current;
    }
    return prev[m];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<string> a, b;
    get(0, n, a);
    b = a;
    int ans = (int)1e9;
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b.size(); j++) {
            int val = lcs(a[i], b[j]);
            if (val == 6) {
                debug(a[i], b[j]);
                return;
            }
            ans = min(ans, val);
        }
    }
    debug(ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
