#include <bits/stdc++.h>
using namespace std;

/*
    Once the graph with disabled cells is built up, running bfs thereafter from
    the top-left cell to the bottom-right cell becomes pretty straightforward.

    Since we are running bfs on an implicit graph, maintaining two separate
    queues for x and y coordinates is a useful technique when traversing the grid
    breadth-wise.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
#define x real()
#define y imag()
#define M_PI 3.14159265358979323846
typedef double T;
typedef complex<T> pt;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
inline istream& skip_endl(istream &is) { return is.ignore(numeric_limits<streamsize>::max(),'\n'); }

int r, c, m, n, l, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> r >> c, r || c) {
        vvi g(r, vi(c));
        cin >> m;
        while(m--) {
            cin >> a >> b;
            g[a-1][b-1] = -1;
        }
        cin >> n;
        while(n--) {
            cin >> a >> b >> l;
            a--; b--;
            int bound = pow(l, 2);
            forn(i, -l, l) {
                forn(j, -l, l) {
                    int nx = a + i;
                    int ny = b + j;
                    if(pow(i, 2) + pow(j, 2) > bound || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    g[nx][ny] = -1;
                }
            }
        }
        
        vi dirx = {-1, 0, 1, 0};
        vi diry = {0, 1, 0, -1};
        queue<int> qx;
        queue<int> qy;
        qx.push(0); qy.push(0);
        int dis = 0;
        bool found = false;
        while(!qx.empty()) {
            int q_size = qx.size();
            forn(j, 0, q_size - 1) {
                int poppedx = qx.front(); qx.pop();
                int poppedy = qy.front(); qy.pop();
                forn(i, 0, 3) {
                    int nx = poppedx + dirx[i];
                    int ny = poppedy + diry[i];
                    if(nx == r - 1 && ny == c - 1) {
                        found = true;
                        break;
                    }
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] == -1) continue;
                    g[nx][ny] = -1;
                    qx.push(nx);
                    qy.push(ny);
                }
            }
            dis++;
            if(found)
                break;
        }
        if(found)
            cout << dis << "\n";
        else
            cout << "Impossible.\n";
    }   
    return 0;
}