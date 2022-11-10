#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sp << ' ' <<
#define nl << '\n'

int root(int x) {
    int y = sqrtl(x) + 2;
    while (y * y > x) --y;
    return y;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        map<int, int> dp{{0, 0}}, cur;

        while (N--) {
            int a;
            cin >> a;

            cur[a] = 0;
            queue<int> q;
            q.push(a);

            while (!empty(q)) {
                int u = q.front();
                q.pop();

                vector<int> vs;
                if (1 < u) vs.push_back(root(u));
                if (u <= (int)1e9) vs.push_back(u * u);

                for (int v : vs)
                    if (cur.find(v) == end(cur)) cur[v] = cur[u] + 1, q.push(v);
            }

            int prefMin = 1e18;

            for (auto &[i, j] : cur) {
                auto k = dp.upper_bound(i);
                j += prev(k)->second;

                j = min(j, prefMin);
                prefMin = min(prefMin, j);
            }

            swap(cur, dp);
            cur.clear();
        }

        int ans = 1e18;
        for (auto [i, j] : dp) ans = min(ans, j);

        cout << ans nl;
    }
}
