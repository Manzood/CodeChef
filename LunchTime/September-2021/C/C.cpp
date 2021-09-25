#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        bool win = false;
        if (n % 2 == 0 && n > 2) {
            win = true;
        } else if (n == 3 || n == 1) {
            win = true;
        }
        if (win) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
}
