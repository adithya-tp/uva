#include <bits/stdc++.h>
using namespace std;

/*
    A bipartite graph check. Do a BFS to color neighbours with the opposite color as 
    the current node, if they haven't been colored. If they have been colored, and
    they are the same color as the current node, then the graph isn't BICOLORABLE.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e, a, b;
    while(true) {
        cin >> n;
        if(!n) break;
        cin >> e;
        vector<vi> g(n);
        vi colors(n, -1);
        bool bipar = true;
        while(e--) {
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        queue<int> q;
        q.push(0);
        colors[0] = 0;
        while(!q.empty()) {
            int popped = q.front(); q.pop();
            for(int neigh : g[popped]) {
                if(colors[neigh] == -1) {
                    colors[neigh] = colors[popped] ^ 1;
                    q.push(neigh);
                } else {
                    if(colors[neigh] == colors[popped]) {
                        bipar = false;
                        break;
                    }
                }
            }
            if(!bipar) {
                break;
            }
        }
        if(bipar) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}