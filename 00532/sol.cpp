#include <bits/stdc++.h>
using namespace std;

/*
    Solved by extending BFS to 3 dimensions, affectionately known as 3D BFS.
    Rather than pushing in tuples of coordinates into a single queue, I found
    maintaining three different queues for each coordinate easier to handle.
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

char g[35][35][35];

vi dx = {0, -1, 0, 1, 0, 0};
vi dy = {-1, 0, 1, 0, 0, 0};
vi dz = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char junk;
    int l, r, c, sx, sy, sz, curr_x, curr_y, curr_z, dr, dc, dk;
    while(cin >> l >> r >> c, l || r || c) {
        memset(g, 0, sizeof(g));
        forn(i, 0, l - 1) {
            forn(j, 0, r - 1) {
                forn(k, 0, c - 1) {
                    cin >> g[i][j][k];
                    if(g[i][j][k] == 'S') {
                        sx = j; sy = k; sz = i;
                    }
                }
            }
        }

        queue<int> x, y, z;
        x.push(sx); y.push(sy); z.push(sz);
        int level = 0;
        bool found = false;
        while(!x.empty()) {
            int q_size = x.size();
            forn(i, 0, q_size - 1) {
                curr_x = x.front(); x.pop();
                curr_y = y.front(); y.pop();
                curr_z = z.front(); z.pop();
                if(g[curr_z][curr_x][curr_y] == 'E') {
                    found = true;
                    break;
                }
                forn(d, 0, 6 - 1) {
                    dr = curr_x + dx[d];
                    dc = curr_y + dy[d];
                    dk = curr_z + dz[d];
                    if(dr < 0 || dc < 0 || dk < 0 || dr >= r || dc >= c ||  dk >= l || g[dk][dr][dc] == '#') continue;
                    if(g[dk][dr][dc] == 'E') {
                        found = true;
                        break;
                    }
                    g[dk][dr][dc] = '#';
                    x.push(dr);
                    y.push(dc);
                    z.push(dk);
                }
            }
            level++;
            if(found)
                break;
        }
        if(found)
            cout << "Escaped in " << level << " minute(s).\n";
        else
            cout << "Trapped!\n";

    }
    return 0;
}