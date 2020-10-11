#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n;
    scanf("%d", &n);
    string s, t;
    cin >> s >> t;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (i+j < n && s[i+j] == t[j]) {
            j++;
            if (i+j == n) {
                mx = max(mx, i);
                break;
            }
        }
    }
    printf("%d\n",  mx);
}