#include <bits/stdc++.h>
using namespace std;

/*
    The Giovanni Number of a node is just the distance of that node from Giovanni, that is, node 0.
    A simple bfs while maintaing a distance vector is enough to solve the problem.
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
    int t, u, v, p, m, c = 0;
    string s;
    cin >> t;
    while(t--){
        cin >> p >> m;
        if(c)
            cout << "\n";
        c = 1;
        vvi g(p);
        while(m--) {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        vi dis(p, -1);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int popped = q.front();
            q.pop();
            for(int i : g[popped]) {
                if(dis[i] == -1) {
                    dis[i] = dis[popped] + 1;
                    q.push(i);
                }
            }
        }
        forn(i, 1, dis.size() - 1) {
            cout << dis[i] << "\n";
        }
    }
    return 0;
}