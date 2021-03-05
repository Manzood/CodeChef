#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int evena = a/2;
        int evenb = b/2;
        int ans = evena * evenb + (b - evenb) * (a - evena);
        printf("%d\n", ans);
    }
}