#include <bits/stdc++.h>
using namespace std;

/*
    Max boom size is the size of the queue at each level of bfs and 
    max days is the level you are currently at.
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
    int n, q, num, v;
    while(cin >> n) {
        vvi g(n);
        forn(i, 0, n - 1) {
            cin >> num;
            forn(j, 0, num - 1) {
                cin >> v;
                g[i].pb(v);
            }
        }

        cin >> n;
        forn(i, 0, n - 1) {
            cin >> v;
            vi vis(g.size());
            queue<int> q;
            q.push(v);
            vis[v] = true;
            int max_days = 1, max_boom = 1, days = 0;
            while(!q.empty()) {
                int q_size = q.size();
                if(q_size > max_boom) {
                    max_boom = q_size;
                    max_days = days;
                }
                forn(j, 0, q_size - 1) {
                    int popped = q.front();
                    q.pop();
                    for(int neigh : g[popped]) {
                        if(!vis[neigh]) {
                            vis[neigh] = true;
                            q.push(neigh);
                        }
                    }
                }
                days++;
                
            }
            if(days == 1) {
                cout << "0\n";
            } else {
                cout << max_boom << " " << max_days << "\n";
            }
        }
    }
    return 0;
}