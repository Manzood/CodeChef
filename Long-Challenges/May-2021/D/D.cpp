#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        // not reachable if...
        // x > o + 1
        // x < o
        // both have somehow won

        // if one wins, or if board is full, and reachable, print 1
        // else if reachable, print 2
        // else print 3

        vector <string> s(3);
        int x = 0, o = 0;
        for (int i = 0; i < 3; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i][j] == 'X') x++;
                else if (s[i][j] == 'O') o++;
            }
        }
        bool reachable = true;
        if (x > o + 1 || x < o) reachable = false;
        // check rows
        int xwon = 0;
        int owon = 0;
        for (int i = 0; i < 3; i++) {
            int curjx = 0;
            int curjo = 0;
            for (int j = 0; j < 3; j++) {
                if (s[i][j] == 'X') curjx++;
                if (s[i][j] == 'O') curjo++;
            }
            if (curjx == 3) xwon++;
            if (curjo == 3) owon++;
        }
        // check columns
        for (int i = 0; i < 3; i++) {
            int curjx = 0;
            int curjo = 0;
            for (int j = 0; j < 3; j++) {
                if (s[j][i] == 'X') curjx++;
                if (s[j][i] == 'O') curjo++;
            }
            if (curjx == 3) xwon++;
            if (curjo == 3) owon++;
        }
        // check diagonal
        int curx = 0;
        int curo = 0;
        for (int i = 0; i < 3; i++) {
            if (s[i][i] == 'X') curx++;
            if (s[i][i] == 'O') curo++;
        }
        if (curx == 3) xwon++;
        if (curo == 3) owon++;
        // check other diagonal
        curx = 0;
        curo = 0;
        for (int i = 0; i < 3; i++) {
            if (s[i][2 - i] == 'X') curx++;
            if (s[i][2 - i] == 'O') curo++;
        }
        if (curx == 3) xwon++;
        if (curo == 3) owon++;

        // debug(xwon);
        // debug(owon);

        if (xwon >= 1 && owon >= 1) reachable = false;
        if (xwon && x == o) reachable = false;
        if (owon && x > o) reachable = false;
        if (reachable && (xwon > 0 || owon > 0 || x + o == 9)) printf("1\n");
        else if (reachable) printf("2\n");
        else printf("3\n");
    }
}
