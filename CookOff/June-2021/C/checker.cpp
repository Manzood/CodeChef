#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int m;
    scanf("%lld", &m);
    vector <vector <int>> moves;
    if (m > 0) {
        vector <int> temp;
        moves.push_back (temp);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                int te;
                scanf("%lld", &te);
                moves[i].push_back(te);
            }
        }
    }
    freopen ("in", "r", stdin);
    int t;
    scanf("%lld", &t);
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        moves[i][0]--;
        moves[i][1]--;
        moves[i][2]--;
        a[moves[i][2]] = a[moves[i][1]] ^ a[moves[i][0]];
    }
    if (m != -1) {
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                assert ((a[i+1] ^ a[i]) > 0);
                if (i - 1 >= 0) {
                    assert ((a[i-1] ^ a[i] ^ a[i+1]) == a[i]);
                }
            }
        }
    } else {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                if ((a[i+1] ^ a[i]) == 0) found = true;
                if (i - 1 >= 0) {
                    if ((a[i-1] ^ a[i] ^ a[i+1]) != a[i]) found = true;
                }
            }
        }
        assert (found == true);
    }
}

