#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct ufds {
    vector<int> root, sz;
    int n;

    void init(int nn) {
        n = nn;
        root.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) root[i] = i;
    }

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (sz[y] > sz[x]) swap(x, y);
        sz[x] += sz[y];
        root[y] = x;
        return true;
    }
};

void Solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<array<int, 3>> a;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t;
            if (x[i] == x[j] || y[i] == y[j]) {
                t = (abs(x[i] - x[j] + y[i] - y[j]) + 1) / 2;
            } else {
                t = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
            }

            a.push_back({t, i, j});
        }
    }

    sort(a.begin(), a.end());

    ufds uf;
    uf.init(n);
    int comps = n;

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    for (auto pi : a) {
        int t = pi[0];
        int x = pi[1];
        int y = pi[2];
        if (uf.unite(x + 1, y + 1)) {
            comps--;
        }

        if (comps == 1) {
            cout << t << "\n";
            return;
        }
    }
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
