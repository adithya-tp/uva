#include <bits/stdc++.h>
using namespace std;

/*
    We must go deeper. ``Dfs``ception to find the number of dots inside a die.
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

vi dr = {0, 1, 0, -1};
vi dc = {1, 0, -1, 0};
int dot = 0;

void dfs_dot(int r, int c, vvc& g) {
    if(r < 0 || r >= g.size() || c < 0 || c >= g[0].size() || g[r][c] != 'X') return;
    g[r][c] = '.';
    for(int i = 0; i < 4; i++) {
        dfs_dot(r + dr[i], c + dc[i], g);
    }
}

void dfs_dice(int r, int c, vvc& g) {
    if(r < 0 || r >= g.size() || c < 0 || c >= g[0].size() || g[r][c] == '.') return;
    if(g[r][c] == 'X') {
        dot++;
        dfs_dot(r, c, g);
    }
    g[r][c] = '.';
    for(int i = 0; i < 4; i++) {
        dfs_dice(r + dr[i], c + dc[i], g);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, c = 0;
    string s;
    while(cin >> m >> n) {
        c++;
        if(!(m || n)) break;
        swap(m, n);
        vvc g;
        vi dots;
        forn(i, 0, m - 1) {
            cin >> s;
            vc line(s.begin(), s.end());
            g.pb(line);
        }
        forn(i, 0, m - 1) {
            forn(j, 0, n - 1) {
                if(g[i][j] != '.') {
                    dot = 0;
                    dfs_dice(i, j, g);
                    if(dot)
                        dots.pb(dot);
                }
            }
        }
        cout << "Throw " << c << "\n";
        sort(dots.begin(), dots.end());
        forn(i, 0, dots.size() - 1) {
            cout << dots[i];
            if(i != dots.size() - 1)
                cout << " ";
        }
        cout << "\n\n";
    }
    return 0;
}