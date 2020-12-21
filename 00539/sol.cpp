#include <bits/stdc++.h>
using namespace std;

/*
    Recursive backtracking solution while keeping track of visited edges, 
    rather than keeping track of visited nodes.
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

int max_len, edges = 0;
int v[30][30];

void backtrack(vvi&g, int i) {
    for(int n : g[i]) {
        if(!v[i][n]) {
            edges++;
            v[i][n] = 1;
            v[n][i] = 1;
            backtrack(g, n);
            v[i][n] = 0;
            v[n][i] = 0;
            edges--;
        } else {
            max_len = max(max_len, edges);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e, a, b;
    while(cin >> n >> e, n || e) {
        vvi g(n);
        forn(i, 0, e - 1) {
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        max_len = INT_MIN;
        forn(i, 0, n - 1) {
            memset(v, 0, sizeof v);
            backtrack(g, i);
        }
        cout << max_len << "\n";
    }
    return 0;
}