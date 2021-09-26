#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    string s1, s2;
    cin >> s1 >> s2;
    sort (s1.begin(), s1.end());
    sort (s2.begin(), s2.end());
    reverse(s2.begin(), s2.end());
    int n = s1.size();

    string ans;
    for (int i = 0; i < n; i++) {
        ans += '#';
    }

    int ptr1 = 0;
    int ptr2 = 0;
    int ansptr = 0;
    int endptr = n - 1;
    int endptr1 = (n + 1) / 2 - 1;
    int endptr2 = n / 2 - 1;
    for (int i = 0; i < n; i++) {
        if (s1[ptr1] < s2[ptr2]) {
            // normal game
            // put s1 in smallest possible index, same with s2
            if (i % 2 == 0) {
                ans[ansptr] = s1[ptr1];
                ptr1++;
            } else {
                ans[ansptr] = s2[ptr2];
                ptr2++;
            }
            ansptr++;
        } else {
            // put everything as far back as possible, traverse s1 and s2 in reverse order
            if (i % 2 == 0) {
                ans[endptr] = s1[endptr1];
                endptr1--;
            } else {
                ans[endptr] = s2[endptr2];
                endptr2--;
            }
            endptr--;
        }
    }

    cout << ans << "\n";
}
