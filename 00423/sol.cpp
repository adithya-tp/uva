#include <bits/stdc++.h>
using namespace std;

/*
    Floyd-Warshall to the rescue! Once we've found the shortest paths for all pairs, 
    we can then iterate through just row 0 and find the max, since we'd like to 
    find the bottleneck from the first node (node 0), that is, the 
    "longest shortest path" from node 0 to other processors.
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
    int n;
    string num;
    while(cin >> n) {
        vvi g(n, vi(n, INF));
        forn(i, 1, n - 1) {
            forn(j, 0, i - 1) {
                cin >> num;
                if(num != "x") {
                    g[i][j] = stoi(num);
                    g[j][i] = stoi(num);
                }
            }
        }
        forn(i, 0, n - 1) g[i][i] = 0;

        forn(k, 0, n - 1) {
            forn(i, 0, n - 1) {
                forn(j, 0, n - 1) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int ans = INT_MIN;
        forn(j, 0, n - 1) {
            if(g[0][j] != INF)
                ans = max(ans, g[0][j]);
        }
        cout << ans << "\n";   
    }
    return 0;
}