#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] > a[i-1] + 1) {
            ans = false;
        }
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}