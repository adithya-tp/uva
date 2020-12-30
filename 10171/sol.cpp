#include <bits/stdc++.h>
using namespace std;

/*
    Maintain two separate matrices for 'young' roads and 'old' roads.

    Once we get all pairs of shortest paths (APSP) for each of the nodes connected
    by young roads and old roads respectively by feeding in the above two matrices into 
    the Floyd-Warshall Algorithm, we can then look at the current locations 
    of the young guy and the professor.

    We can then minimize the combined shortest path by iterating over the 
    row of the start positions of each person in the corresponding APSP matrices.
    We also maintain a vector of the optimal meeeting points.
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
    int e, w;
    char typ, dir, u, v;
    while(cin >> e, e) {
        vvi gy(26, vi(26, INF));
        vvi gm(26, vi(26, INF));
        forn(i, 0, e - 1) {
            cin >> typ >> dir >> u >> v >> w;
            if(typ == 'Y') {
                gy[u - 'A'][v - 'A'] = w;
                if(dir == 'B') {
                    gy[v - 'A'][u - 'A'] = w;
                }
            } else {
                gm[u - 'A'][v - 'A'] = w;
                if(dir == 'B') {
                    gm[v - 'A'][u - 'A'] = w;
                }
            }
        }

        forn(k, 0, 25) {
            forn(i, 0, 25) {
                forn(j, 0, 25) {
                    if(i == j) {
                        gy[i][j] = gm[i][j] = 0;
                        continue;
                    }
                    gy[i][j] = min(gy[i][j], gy[i][k] + gy[k][j]);
                    gm[i][j] = min(gm[i][j], gm[i][k] + gm[k][j]);
                }
            }
        }

        cin >> u >> v;
        int s = u - 'A';
        int d = v - 'A';
        int min_sum = INT_MAX;
        vc meet = {'\0'};
        forn(i, 0, 25) {
            if(gy[s][i] != INF && gm[d][i] != INF && gy[s][i] + gm[d][i] <= min_sum) {
                if(gy[s][i] + gm[d][i] < min_sum) {
                    meet.clear();
                    meet.pb(i + 'A');
                    min_sum = gy[s][i] + gm[d][i];
                } else if(gy[s][i] + gm[d][i] == min_sum) {
                    meet.pb(i + 'A');
                }
            }
        }
        if(min_sum == INT_MAX)
            cout << "You will never meet.\n";
        else {
            cout << min_sum;
            for(char c : meet) {
                cout << " " << c;
            }
            cout << "\n";
        }
    }
    return 0;
}