#include <bits/stdc++.h>
using namespace std;

/*
    This is an SSSP problem that could be solved with Dijkstra's. However,
    since the input graph is small and consists of atmost 10 nodes, we might
    as well code up the easier to implement Floyd-Warshall. 

    We will also maintain a 2D "parent" matrix to trace out the path from source
    to destination.
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

int p[20][20];
string path;

void print_path(int start, int end) {
    if(start != end) {
        print_path(start, p[start][end]);
    }
    path = path + " " + to_string(end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ni, e, v, w, s, d, c = 1;
    while(cin >> ni, ni) {
        vvi g(ni + 1, vi(ni + 1, INF));
        forn(i, 1, ni) {
            forn(j, 1, ni) {
                p[i][j] = i;
            }
        }

        forn(i, 1, ni) {
            cin >> e;
            forn(j, 0, e - 1) {
                cin >> v >> w;
                g[i][v] = w;
            }
        }

        cin >> s >> d;

        forn(k, 1, ni) {
            forn(i, 1, ni) {
                forn(j, 1, ni) {
                    if(g[i][k] + g[k][j] < g[i][j]) {
                        p[i][j] = p[k][j];
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }

        path = "";
        print_path(s, d);
        cout << "Case " << c++ << ": Path =" << path << "; " << g[s][d] << " second delay\n";
    }
    return 0;
}