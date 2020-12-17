#include <bits/stdc++.h>
using namespace std;

/*
    Store all values in an adjacency matrix and then print the required output
    by traversing column-wise on the adjacency matrix.
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, nz, val;
    int last_c = -1;
    while(!cin.eof()) {
        cin >> n >> m;
        if(cin.eof())
            break;
        vvi g(n + 1, vi(m + 1, 0));
        string blank;
        forn(i, 1, n) {
            cin >> nz;
            if(!nz) {
                continue;
            }
            vi idx(nz);
            forn(j, 0, nz - 1) {
                cin >> idx[j];
            }
            for(int id : idx) {
                cin >> val;
                g[i][id] = val;
            }
        }
        cout << m << " " << n << "\n";
        forn(j, 1, m) {
            int c = 0;
            vi idx;
            forn(i, 1, n) {
                if(g[i][j]) {
                    c++;
                    idx.pb(i);
                }
            }
            cout << c;
            if(!c) {
                cout << "\n\n";
            } else {
                for(int id : idx)
                    cout << " " << id;
                cout << "\n";
                for(int x = 0; x <= idx.size() - 1; x++) {
                    cout << g[idx[x]][j];
                    if(x != idx.size() - 1) {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
            last_c = c;
        }
    }
    return 0;
}