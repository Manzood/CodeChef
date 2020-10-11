#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        string s;
        string vowels = "aeiou";
        cin >> s;
        int n = sz(s);
        int ind = 0;
        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    if (j < ind) {
                        good = false;
                    }
                    ind = max(ind, j);
                    break;
                }
            }
        }
        bool bad = true;
        ind = 4;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    if (j > ind) {
                        bad = false;
                    }
                    ind = min(ind, j);
                    break;
                }
            }
        }
        if (good) {
            printf("Good\n");
        }
        else if (bad) {
            printf("Worst\n");
        }
        else {
            printf("Bad\n");
        }
    }
}