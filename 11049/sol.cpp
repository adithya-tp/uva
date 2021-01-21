#include <bits/stdc++.h>
using namespace std;

/*
    Modeling the graph is the hard part. Here I've chosen to represent each 
    wall with its own cell. If the wall takes up a space of 1 unit, then
    it takes up two cells in my graph representation.

    I have reversed the row column coordinates when building the graph,
    because it was easier for me to think that way.

    For the bfs traversal, a neighbouring cell (which is two cells away in the 
    horizontal and vertical directions) is only queued if the adjacent
    horizontal or vertical cell is not a wall ('#') or has not been visited.

    After making this tweak to the bfs search, I also maintain a hashmap 
    of parents to generate the shortest path later on.
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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, x1, y1, x2, y2;
    while(cin >> a >> b, a || b) {
        vvc g(13, vc(13, '.'));
        a = 2 * a - 1; b = 2 * b - 1;
        g[b][a] = 'S';
        unordered_map<ii, ii, hash_pair> parent;
        parent[make_pair(b, a)] = {-1, -1};
        queue<int> qx, qy;
        qx.push(b); qy.push(a);
        g[b][a] = '#';
        
        cin >> a >> b;
        a = 2 * a - 1; b = 2 * b - 1;
        g[b][a] = 'E';
        forn(i, 0, 2) {
            cin >> x1 >> y1 >> x2 >> y2;
            x1 *= 2; y1 *= 2; x2 *= 2; y2 *= 2;
            if(x1 == x2) {
                forn(j, y1, y2 - 1) {
                    g[j][x1] = '#';
                }
            } else {
                forn(j, x1, x2 - 1) {
                    g[y1][j] = '#';
                }
            }
        }

        vi dx = {-1, 0, 1, 0};
        vi dy = {0, -1, 0, 1};
        bool found = false;
        while(!qx.empty()) {
            int px = qx.front(); qx.pop();
            int py = qy.front(); qy.pop();
            forn(i, 0, 3) {
                int nx = px + dx[i], ny = py + dy[i];
                if(nx < 0 || nx >= 13 || ny < 0 || ny >= 13 || g[nx][ny] == '#' || g[nx][ny] == 'W' || g[nx][ny] == 'P') continue;
                g[nx][ny] = '#';
                nx += dx[i], ny += dy[i];
                if(nx < 0 || nx >= 13 || ny < 0 || ny >= 13) continue;
                parent[make_pair(nx, ny)] = make_pair(px, py);
                if(g[nx][ny] == 'E') {
                    found = true;
                    break;
                }
                g[nx][ny] = '#';
                qx.push(nx);
                qy.push(ny);
            }
            if(found)
                break;
        }
        string path = "";
        ii start = {b, a};
        ii curr_par = parent[start];
        while(curr_par.first != -1) {
            if(curr_par.first == start.first) {
                if(curr_par.second < start.second) {
                    path = 'E' + path;
                } else {
                    path = 'W' + path;
                }
            } else {
                if(curr_par.first < start.first) {
                    path = 'S' + path;
                } else {
                    path = 'N' + path;
                }
            }
            start = curr_par;
            curr_par = parent[start];
        }
        cout << path << "\n";
    }
    return 0;
}