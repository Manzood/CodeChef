#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int)1e9 + 7;

struct segtree {  // zero based indexing
    int size;
    vector<long long> sum;
    vector<long long> m;
    vector<long long> ind;
    vector<long long> mx;
    segtree(int n) {
        // makes size a power of two GE n
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2 * size - 1, 0);
        m.assign(2 * size - 1, inf);
        ind.assign(2 * size - 1, -1);
        mx.assign(2 * size - 1, -inf);
    }
    void build(vector<int>& a) {
        int n = (int)a.size();
        int numzeroes = size - n;
        int counter = 0;
        for (int i = 2 * size - 2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                ind[i] = -1;
                mx[i] = -inf;
            } else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
                ind[i] = n;
            } else {
                sum[i] += sum[2 * i + 1] + sum[2 * i + 2];
                m[i] = min(m[2 * i + 1], m[2 * i + 2]);
                mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
                if (mx[2 * i + 1] > mx[2 * i + 2]) {
                    ind[i] = ind[2 * i + 1];
                } else if (mx[2 * i + 1] == mx[2 * i + 2]) {
                    ind[i] = min(ind[2 * i + 1], ind[2 * i + 2]);
                } else {
                    ind[i] = ind[2 * i + 2];
                }
            }
        }
    }
    void set(int i, int v) {  // setting index i to element v
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            m[x] = v;
            mx[x] = v;
            ind[x] = i;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        m[x] = min(m[2 * x + 1], m[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
        if (mx[2 * i + 1] > mx[2 * i + 2]) {
            ind[i] = ind[2 * i + 1];
        } else if (mx[2 * i + 1] == mx[2 * i + 2]) {
            ind[i] = min(ind[2 * i + 1], ind[2 * i + 2]);
        } else {
            ind[i] = ind[2 * i + 2];
        }
    }
    pair<int, int> getmax(int left, int right) {  // returns max between indexes
        // [left, right - 1], inclusive
        return getmax(left, right, 0, 0, size);
    }
    pair<int, int> getmax(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return {-inf, -1};
        if (lx >= left && rx <= right) return {mx[x], ind[x]};
        int mid = (lx + rx) / 2;
        pair<int, int> s1 = getmax(left, right, 2 * x + 1, lx, mid);
        pair<int, int> s2 = getmax(left, right, 2 * x + 2, mid, rx);
        if (s1.first > s2.first) {
            return s1;
        } else if (s1.first == s2.first) {
            if (s1.second < s2.second)
                return s1;
            else
                return s2;
        }
        return s2;
    }
};

vector<int> getnge(vector<int>& a) {
    int n = (int)a.size();
    vector<int> nge(n, n);
    vector<int> g;
    for (int i = n - 1; i >= 0; i--) {
        while (!g.empty() && a[g.back()] < a[i]) g.pop_back();
        if (!g.empty() && a[g.back()] >= a[i]) nge[i] = g.back();
        g.push_back(i);
    }
    return nge;
}

vector<int> getnse(vector<int>& a) {
    int n = (int)a.size();
    vector<int> nse(n, n);
    vector<int> g;
    for (int i = n - 1; i >= 0; i--) {
        while (!g.empty() && a[g.back()] >= a[i]) g.pop_back();
        if (!g.empty() && a[g.back()] < a[i]) nse[i] = g.back();
        g.push_back(i);
    }
    return nse;
}

void solve([[maybe_unused]] int test) {
    // get nge(geq), nse(lt), mx in a subarray with index
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> nge = getnge(a);
    vector<int> nse = getnse(a);
    segtree st(n);
    st.build(a);
    vector<int> f(n, -1);
    vector<bool> found(n, false);
    for (int i = 0; i < n; i++) {
        if (found[i]) continue;
        int cur = i;
        int p = cur;
        int ans = n;
        while (p >= i) {
            while (nge[cur] > nse[cur]) {
                cur = nse[cur];
            }
            ans = nge[cur];
            int x = a[p] - 1;
            while (p >= i && (a[p] == x + 1 || nge[cur] >= a[p])) {
                f[p] = ans;
                found[p] = true;
                x = a[p];
                p--;
            }
            if (cur < n)
                cur = nge[cur];
            else {
                ans = n;
                while (p >= i) {
                    f[p] = ans;
                    found[p] = true;
                    p--;
                }
            }
        }
        // if (nge[cur] <= nse[cur]) {
        //     ans = nge[cur];
        // } else {
        //     cur = nse[cur];
        // }
        // while (cur >= i) {
        //     f[cur] = ans;
        //     found[cur] = true;
        //     cur--;
        // }
    }
    // debug(f);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        l--;
        r--;
        int ind = st.getmax(l, r + 1).second;
        int out = a[ind] + 1;
        if (f[ind] > r) out = a[ind];
        printf("%lld\n", out);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
