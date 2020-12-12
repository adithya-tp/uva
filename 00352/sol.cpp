#include <bits/stdc++.h>
using namespace std;

/*
    Count the number of connected components using DFS.
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

vi dx = {1, 1, 0, -1, -1, -1, 0, 1};
vi dy = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c, vvi& g, vvi& v) {
    if(r < 0 || r >= g.size() || c < 0 || c >= g[0].size()) return;
    if(!g[r][c] || v[r][c]) return;
    v[r][c] = 1;
    for(int i = 0; i < 8; i++) {
        dfs(r + dx[i], c + dy[i], g, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c = 0;
    while(cin >> n) {
        c++;
        int cc = 0;
        vvi g(n);
        vvi v(n, vi(n, 0));
        string s;
        forn(i, 0, n - 1) {
            cin >> s;
            for(char ch : s) {
                g[i].pb(ch - '0');
            }
        }

        forn(i, 0, n - 1) {
            forn(j, 0, n - 1) {
                if(!v[i][j] && g[i][j]) {
                    cc++;
                    dfs(i, j, g, v);
                }
            }
        }

        cout << "Image number " << c << " contains " << cc << " war eagles.\n";
    }
    return 0;
}