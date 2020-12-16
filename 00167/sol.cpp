#include <bits/stdc++.h>
using namespace std;

/*
    Solved with recursive backtracking. Used additional data-structures
    in the form of bitsets for making faster decisions to prune a search
    space.

    It is important to reset them after each backtrack call returns.
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

int t, g[8][8], max_sum, sum;
bitset<15> row, ld, rd;

bool canPlace(int r, int c) {
    return (!row[r] && !ld[r - c + 8 - 1] && !rd[r + c]);
}

void backtrack(int c) {
    if(c == 8) {
        max_sum = max(max_sum, sum);
        return;
    }
    forn(r, 0, 7) {
        if(canPlace(r, c)) {
            sum += g[r][c];
            row[r] = ld[r - c + 8 - 1] = rd[r + c] = true;
            backtrack(c + 1);
            row[r] = ld[r - c + 8 - 1] = rd[r + c] = false;
            sum -= g[r][c];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        forn(i, 0, 7) {
            forn(j, 0, 7) {
                cin >> g[i][j];
            }
        }
        sum = 0;
        max_sum = INT_MIN;
        backtrack(0);
        cout << setw(5) << max_sum << endl;
    }
    return 0;
}