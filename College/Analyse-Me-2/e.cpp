#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        vector <int> backward(n);
        vector <int> forward(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            mx = max(a[i], mx);
            forward[i] = mx;
        }
        int mi = a[n-1] + 1;
        for (int i = n-1; i >= 0; i--) {
            mi = min(mi, a[i]);
            backward[i] = mi;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i < n-1 && forward[i] < backward[i+1])
                count++;
        }
        if (count & 1) {
            printf("Jeel\n");
        }
        else {
            printf("Ashish\n");
        }
    }
}