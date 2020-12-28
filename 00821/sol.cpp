#include <bits/stdc++.h>
using namespace std;

/*
    Since we need to sum shortest paths between all vertex pairs (i, j)
    (make sure you don't consider i = j), Floyd-Warshall is a good fit for
    this problem. Keep track of "non-infinite" sums that don't lead to the
    same node and keep track of the number of elements that contribute to this
    sum so as to find the average path length. 
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
    int u, v, c = 1;
    while(cin >> u >> v, u || v) {
        vvi g(101, vi(101, INF));
        g[u][v] = 1;
        while(cin >> u >> v, u || v) {
            g[u][v] = 1;
        }
        int non_inf = 0;
        forn(k, 1, 100) {
            forn(i, 1, 100) {
                forn(j, 1, 100) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        double sum = 0.0;
        forn(i, 1, 100) {
            forn(j, 1, 100) {
                if(g[i][j] != INF && i != j) {
                    sum += g[i][j];
                    non_inf++;
                }
            }
        }
        cout << "Case " << c++ << ": average length between pages = " << fixed << setprecision(3) << sum / non_inf << " clicks\n";
    }
    return 0;
}