#include <bits/stdc++.h>
using namespace std;

/*
    Since we only have atmost 22 nodes, we can find all pairs shortest paths using
    Floyd Warshall. Once we've got this matrix, the total cost is for each house i,
    is the sum of the costs from all sources, which is the sum of costs in column i of the matrix.
    We'll be breaking ties automatically without requiring an extra condition, if we start computing
    costs starting from house 1 (since its asks for numerically first, not lexicographically first, in case of ties).
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
    int n, e, u, v, w, c = 1;
    string s;
    while(cin >> n >> e, n || e) {
        vvi g(n + 1, vi(n + 1, INF));
        int k = 1;
        unordered_map<int, string> n2i;
        forn(i, 0, n - 1) {
            cin >> s;
            n2i[k++] = s;
        }

        forn(i, 0, e - 1) {
            cin >> u >> v >> w;
            g[u][v] = w;
            g[v][u] = w;
        }

        forn(k, 1, n) {
            forn(i, 1, n) {
                forn(j, 1, n) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int ans = INT_MAX;
        int ans_i;
        forn(j, 1, n) {
            int sum = 0;
            forn(i, 1, n) {
                if(i != j) {
                    sum += g[i][j];
                }
            }
            if(sum < ans) {
                ans = sum;
                ans_i = j;
            }
        }
        cout << "Case #" << c++ << " : " << n2i[ans_i] << "\n";
    }
    return 0;
}