#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

pair<int, int> get_time (string s) {
    int a[2] = {0, 0};
    int ind = 0;
    for (auto x: s) {
        if (x == 'M') ind++;
        else if (x == 'P') {
            if (a[ind] < 1200) a[ind] += 1200;
        } else if (x == 'A') {
            if (a[ind] >= 1200) a[ind] -= 1200;
        } else if (x != ':' && x != ' ') {
            a[ind] *= 10;
            a[ind] += x - '0';
        }
    }
    return {a[0], a[1]};
}

int32_t main() {
    int t;
    cin >> t;
    string te;
    getline (cin, te);
    while (t--) {
        string p;
        getline (cin, p);
        int p_time = 0;
        for (auto x: p) {
            if (x == 'P') {
                if (p_time < 1200) p_time += 1200;
            }
            else if (x == 'A') {
                if (p_time >= 1200) {
                    p_time -= 1200;
                }
            } else if (x != ':' && x != ' ' && x != 'M') {
                p_time *= 10;
                p_time += x - '0';
            }
        }
        // debug(p_time);
        int n; scanf("%lld", &n);
        getline (cin, te);
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            pair <int, int> temp = get_time (s);
            // debug(temp.first);
            // debug(temp.second);
            if (temp.first > temp.second) swap(temp.first, temp.second);
            if (temp.first <= p_time && temp.second >= p_time) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%lld", ans[i]);
        }
        printf("\n");
    }
}
