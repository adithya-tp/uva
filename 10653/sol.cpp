#include <bits/stdc++.h>
using namespace std;

/*
    Perform bfs on an implicit graph. Encode each cell as a single number in the 
    range [0, r * c - 1] when tracking their distance.
    The neighbour cells that get pushed into the queue are those that haven't been visited or
    are within bounds or don't have a bomb in them.
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

vi dx = {-1, 0, 1, 0};
vi dy = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c, x, y, rows, nums;
    int sx, sy, dsx, dsy;
    while(cin >> r >> c, r || c) { 
        vvi bombs(r, vi(c, 0));
        cin >> rows;
        forn(i, 0, rows - 1) {
            cin >> x >> nums;
            forn(i, 0, nums - 1) {
                cin >> y;
                bombs[x][y] = 1;
            }
        }
        cin >> sx >> sy >> dsx >> dsy;
        vi dis(r * c, -1);
        queue<int> q;
        q.push(sx * c + sy);
        dis[sx * c + sy] = 0;
        int x = 0;
        while(!q.empty()) {
            int popped = q.front(); q.pop();
            int curr_r = popped / c, curr_c = popped - (curr_r * c);
            for(int i = 0; i < 4; i++) {
                int dr = curr_r + dx[i], dc = curr_c + dy[i];
                if(dr < 0 || dr >= r || dc < 0 || dc >= c || dis[dr * c + dc] != -1 || bombs[dr][dc]) continue;
                
                if(dis[dr * c + dc] == -1) {
                    dis[dr * c + dc] = dis[popped] + 1;
                    q.push(dr * c + dc);
                }
            }
        }

        cout << dis[dsx * c + dsy] << "\n";
    }
    return 0;
}