#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string to_find = "saba";

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int ptr = 0;
        for (int j = 0; j < m; j++) {
            if (to_find[ptr] == a[i][j]) {
                ptr++;
            } else {
                ptr = 0;
                if (a[i][j] == 's') {
                    ptr = 1;
                }
            }

            if (ptr == 4) {
                ans++;
                ptr = 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (to_find[ptr] == a[i][j]) {
                ptr++;
            } else {
                ptr = 0;
                if (a[i][j] == 's') {
                    ptr = 1;
                }
            }

            if (ptr == 4) {
                ans++;
                ptr = 0;
            }
        }
    }

    // searching diagonally
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool found = true;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (i + k < n && j + k < m) {
                    cnt++;
                    if (a[i+k][j+k] != to_find[k]) {
                        found = false;
                    }
                }
            }
            if (cnt < 4) found = false;
            if (found) ans++;
        }
    }

    // flip the grid

    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
    }

    for (int i = 0; i < n; i++) {
        int ptr = 0;
        for (int j = 0; j < m; j++) {
            if (to_find[ptr] == a[i][j]) {
                ptr++;
            } else {
                ptr = 0;
                if (a[i][j] == 's') {
                    ptr = 1;
                }
            }

            if (ptr == 4) {
                ans++;
                ptr = 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (to_find[ptr] == a[i][j]) {
                ptr++;
            } else {
                ptr = 0;
                if (a[i][j] == 's') {
                    ptr = 1;
                }
            }

            if (ptr == 4) {
                ans++;
                ptr = 0;
            }
        }
    }

    // searching diagonally
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool found = true;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (i + k < n && j + k < m) {
                    cnt++;
                    if (a[i+k][j+k] != to_find[k]) {
                        found = false;
                    }
                }
            }
            if (cnt < 4) found = false;
            if (found) ans++;
        }
    }

    printf("%lld\n", ans);
}
