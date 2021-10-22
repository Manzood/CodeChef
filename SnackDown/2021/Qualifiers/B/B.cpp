#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        vector <int> r(5);
        int ind = 0, e = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%lld", &r[i]);
            if (r[i] == 1) ind++;
            if (r[i] == 2) e++;
        }
        if (ind > e) {
            printf("INDIA\n");
        } else if (e > ind) {
            printf("ENGLAND\n");
        } else {
            printf("DRAW\n");
        }
    }
}
