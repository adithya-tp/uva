#include <bits/stdc++.h>
using namespace std;

/*
    Since we have atmost 100 nodes, Floyd-Warshall can be used as an intermediate
    step to find our answer. 
    
    The question is about finding the shortest time required for the commandos to
    place bombs in all buildings starting from node 's' (source) and gather up at node 'e' (destination).
    
    The question does NOT ask for the shortest time / path length to get from the source node
    to the destination node. What we really need to find is a node / building (n) such that going from the source 's'
    to 'n' and subsequently to the destination 'e', that is, max(shortest_path[s][i] + shortest[i][e]). This is the
    shortest time that'll take to place a bomb in every single building, because this 'n' is the bottle-neck. 
    
    Floyd-Warshall factors into this because we are maximizing over all shortest paths from the source to 
    desination via all possible intermediate nodes.
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
    int t, n, e, u, v, s, d, c = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        vvi g(n, vi(n, INF));
        forn(i, 0, n - 1) {
            g[i][i] = 0;
        }
        cin >> e;
        forn(i, 0, e - 1) {
            cin >> u >> v;
            g[u][v] = 1;
            g[v][u] = 1;
        }
        cin >> s >> d;

        forn(k, 0, n - 1) {
            forn(i, 0, n - 1) {
                forn(j, 0, n - 1) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int ans = INT_MIN;
        forn(i, 0, n - 1) {
            forn(j, 0, n - 1) {
                ans = max(ans, g[s][i] + g[i][d]);
            }
        }
        cout << "Case " << c++ << ": " << ans << "\n";
    }
    return 0;
}