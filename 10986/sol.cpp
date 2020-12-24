#include <bits/stdc++.h>
using namespace std;

/*
    Dijkstra's shortest path; implemented the Lazy version here.
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, e, src, dst, curr_node, u, v, w, c = 1;
    cin >> t;
    while(t--) {
        cin >> n >> e >> src >> dst;

        vector<vii> g(n);
        forn(i, 0, e - 1) {
            cin >> u >> v >> w;
            g[u].pb(make_pair(v, w));
            g[v].pb(make_pair(u, w));
        }

        vi dis(n, INF);
        dis[src] = 0;
        priority_queue<ii, vii, greater<ii>> pq;
        pq.push(ii(0, src));
        while(!pq.empty()) {
            ii front = pq.top(); pq.pop();
            w = front.first, u = front.second;
            if(u == dst) break;
            // To skip nodes for which the shortest distance have already been found
            if(w > dis[u]) continue;
            for(auto neigh : g[u]) {
                if(dis[u] + neigh.second < dis[neigh.first]) { 
                    dis[neigh.first] = dis[u] + neigh.second;
                    pq.push(ii(dis[neigh.first], neigh.first));
                }
            }
        }
        cout << "Case #" << c++ << ": ";
        if(dis[dst] == INF)
            cout << "unreachable\n";
        else
            cout << dis[dst] << "\n";

    }
    return 0;
}