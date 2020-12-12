#include <bits/stdc++.h>
using namespace std;

/*
    To count the number of oil pockets, do a DFS to count the 
    number of connected components on the implicit graph.
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

vi dr = {1, 1, 0, -1, -1, -1, 0, 1};
vi dc = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c, vvc& g, vvi& v) {
    if(r < 0 || r >= g.size() || c < 0 || c >= g[0].size()) return;
    if(g[r][c] != '@' || v[r][c]) return;
    v[r][c] = 1;
    for(int i = 0; i < 8; i++)
        dfs(r + dr[i], c + dc[i], g, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int m, n;
    while(true) {
        int cc = 0;
        cin >> m >> n;
        if(!(m || n)) break;
        vvc g;
        vvi v(m, vi(n, 0));
        forn(i, 0, m - 1) {
            cin >> s;
            vc line(s.begin(), s.end());
            g.pb(line);
        }

        forn(i, 0, m - 1) {
            forn(j, 0, n - 1) {
                if(!v[i][j] && g[i][j] == '@') {
                    cc++;
                    dfs(i, j, g, v);
                }
            }
        }
        cout << cc << "\n";
    }
    return 0;
}