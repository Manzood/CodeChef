#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

bool check (vector <int>& a, int n) {
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            if ((a[i+1] ^ a[i]) == 0) {
                return false;
            }
            if (i - 1 >= 0) {
                if ((a[i-1] ^ a[i] ^ a[i+1]) != a[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        int cnt = 0;
        int p[2];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (i % 2 == 0 && cnt < 2) {
                if (cnt == 0) {
                    p[cnt++] = i;
                } else {
                    if (a[p[cnt - 1]] != a[i]) {
                        p[cnt++] = i;
                    }
                }
            }
        }
        int m = 0;
        if (n > 3) {
            if (cnt > 1) {
                m = n;
                int pos = 1;
                printf("%lld\n", m);
                while (pos < n) {
                    printf("%lld %lld %lld\n", p[0] + 1, p[1] + 1, pos + 1);
                    pos += 2;
                }
                pos = 0;
                while (pos < n) {
                    printf("2 4 %lld\n", pos + 1);
                    pos += 2;
                }
            } else {
                // make every odd indexed element 0
                if (a[p[0]] > 0) {
                    int pos = 1;
                    m = n / 2;
                    printf("%lld\n", m);
                    while (pos < n) {
                        printf("1 3 %lld\n", pos + 1);
                        pos += 2;
                    }
                } else {
                    printf("-1\n");
                }
            }
        } else if (n == 3) {
            vector <vector <int>> moves;
            bool ans = check(a, n);
            for (int i = 0; i < 3 && ans == false; i++) {
                for (int j = 0; j < 3 && ans == false; j++) {
                    if (j == i) continue;
                    else {
                        int z = 0;
                        while (z == i || z == j) z++;
                        moves.push_back ({i, j, z});
                        a[z] = a[i] ^ a[j];
                        if (check (a, n)) ans = true;
                    }
                }
            }
            if (ans) {
                printf("%lld\n", (int) moves.size());
                for (int i = 0; i < (int) moves.size(); i++) {
                    printf("%lld %lld %lld\n", moves[i][0] + 1, moves[i][1] + 1, moves[i][2] + 1);
                }
            } else {
                printf("-1\n");
            }
        } else {
            if (n == 1) {
                printf("0\n");
            } else {
                if (a[0] != a[1]) {
                    printf("0\n");
                } else {
                    printf("-1\n");
                }
            }
        }
    }
}

