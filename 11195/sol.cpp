#include <bits/stdc++.h>
using namespace std;

/*
    This more constrained n-Queens problem can also be solved with recursive backtracking.
    We just have to be more efficient when checking if a given choice of queen placement is valid.
    
    We could trade memory for time by setting three bitset vectors (faster vector<bool>), 
    to keep track of which rows left diagonals and right diagonals are off limits. 
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

char g[20][20];
bitset<30> row, ld, rd;
int cnt, t, c = 1;

void backtrack(int c) {
    if(c == t) {
        cnt++; 
        return;
    }
    forn(i, 0, t - 1) {
        if(g[i][c] != '*' && !row[i] && !ld[i - c + t - 1] && !rd[i + c]) {
            row[i] = ld[i - c + t - 1] = rd[i + c] = true;
            backtrack(c + 1);
            row[i] = ld[i - c + t - 1] = rd[i + c] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(scanf("%d", &t), t) {
        while(getchar() != '\n');
        forn(i, 0, t - 1) {
            gets(g[i]);
        }
        cnt = 0;
        backtrack(0);
        printf("Case %d: %d\n", c++, cnt);
    }
    return 0;
}