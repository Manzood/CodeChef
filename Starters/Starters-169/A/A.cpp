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
    vector<vector<pair<int, int>>> val(32, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        int cnt = 0;
        for (int j = 0; j < 32; j++) {
            if ((1LL << j) & a[i]) {
                cnt++;
            }
        }
        val[cnt].push_back({a[i], i});
    }
    for (int i = 0; i < 32; i++) {
        sort(val[i].begin(), val[i].end());
        vector<int> indList;
        for (auto pp : val[i]) {
            indList.push_back(pp.second);
        }
        sort(indList.begin(), indList.end());
        for (int j = 0; j < (int)indList.size(); j++) {
            int ind = indList[j];
            a[ind] = val[i][j].first;
        }
    }
    if (is_sorted(a.begin(), a.end())) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
