#include <bits/stdc++.h>
using namespace std;

/*
    Since there are atmost 20 nodes, we could run Floyd-Warshall once and answer the many 
    queries that follow, rather than running BFS for each query.
*/
#define pb push_back 
#define forn(i, l, r) for(int i = l; i <= r; i++) 
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
inline istream& skip_endl(istream &is) { return is.ignore(numeric_limits<streamsize>::max(),'\n'); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int u, v, q, c = 1, n;
    string s;
    while(cin >> s) {
        if(!s.size()) break;
        n = stoi(s);
        vvi g(21, vi(21, INF));
        forn(i, 0, 20) {
            g[i][i] = 0;
        }
        forn(i, 1, 19) {
            if(i - 1)
                cin >> n;
            while(n--) {
                cin >> v;
                g[i][v] = g[v][i] = 1;
            }
        }

        forn(k, 1, 20) {
            forn(i, 1, 20) {
                forn(j, 1, 20) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        cout << "Test Set #" << c++ << "\n";
        cin >> q;
        while(q--) {
            cin >> u >> v;
            cout << setw(2) << u << " to " << setw(2) << v << ": " << g[u][v] << "\n";
        }
        cout << "\n";
    }
    return 0; 
}