#include <bits/stdc++.h>
using namespace std;

/*
    Can be solved with recursive backtracking. 
    
    Your choice space is placing a queen in each row and column.
    Ofcourse your choice is only valid only if it doesn't violate the choices
    you made with already placed queens in preceeding columns.

*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

int row[8], t, a, b, line_counter;

bool canPlace(int r, int c) {
    forn(i, 0, c - 1) {
        if(row[i] == r || abs(row[i] - r) == abs(i - c)) {
            return false;
        }
    }
    return true;
}

void backtrack(int c) {
    if(c == 8 && row[b] == a) {
        printf("%2d     ", ++line_counter);
        forn(r, 0, 7) {
            printf(" %d", row[r] + 1);
        }
        printf("\n");
        return;
    }
    forn(r, 0, 7) {
        if(canPlace(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        a--; b--;
        memset(row, 0, sizeof row);
        line_counter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(t) puts("");
    }
    return 0;
}