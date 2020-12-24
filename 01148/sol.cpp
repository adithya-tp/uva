#include <bits/stdc++.h>
using namespace std;

/*
    Normal bfs with a distance vector to keep track of number of
    intermediate camrades between the given nodes.
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
    int t, n, num, u, v, c = 0;
    cin >> t;
    while(t--) {
        if(c)
            cout << "\n";
        c = 1;
        cin >> n;
        vvi g(n);
        forn(i, 0, n - 1) {
            cin >> u >> num;
            forn(j, 0, num - 1) {
                cin >> v;
                g[u].pb(v);
            }
        }
        vi d(n, -1);
        vi vis(n);
        cin >> u >> v;
        queue<int> q;
        q.push(u);
        vis[u] = true;
        while(!q.empty()) { 
            int popped = q.front();
            q.pop();
            for(int i : g[popped]) {
                if(!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                    d[i] = d[popped] + 1;
                }
            }
        }
        cout << u << " " << v << " " << d[v] << "\n";
    }
    return 0;
}