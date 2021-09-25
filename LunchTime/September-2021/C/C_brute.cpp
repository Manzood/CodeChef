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
        int cnt = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                n--;
            } else {
                if (n != 4) {
                    n--;
                } else {
                    n /= 2;
                }
            }
            cnt++;
        }
        cnt % 2 == 1 ? printf("Alice\n") : printf("Bob\n");
    }
}
