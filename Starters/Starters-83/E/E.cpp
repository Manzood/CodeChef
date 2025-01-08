#include "bits/stdc++.h"
using namespace std;
#define int long long

vector <int> query(vector <int>& a) {
    cout << "? ";
    for (auto x: a) {
        cout << x + 1 << " ";
    }
    cout << endl;
    int k;
    vector <int> in((int) a.size(), 0);
    cin >> k;
    if (k == -1) exit(0);
    for (int i = 0; i < k; i++) {
        int val;
        cin >> val;
        in[val - 1] = 1;
    }
    return in;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector <int> a(n);
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < n - 1; i++) {
        vector <int> response = query(a);
        int lastone = -1;
        int cnt = count(response.begin(), response.end(), 1);
        if (cnt == n) break;
        for (int j = 0; j < n; j++) {
            if (response[j] == 1) {
                if (lastone > -1) {
                    reverse(a.begin() + lastone, a.begin() + j);
                }
                lastone = j;
            }
        }
        reverse(a.begin() + lastone, a.end());
    }
    vector <int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i]] = i + 1;
    }
    cout << "! ";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
