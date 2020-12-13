#include <bits/stdc++.h>
using namespace std;

/*
    BFS with two augmentations solves this problem.
    1. Check for ttl == 0, exit condition in addition to q.empty();
    2. In order decrement ttl after each level, run a for loop for the current q_size.
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
    int e, i, j, c = 1;
    while(scanf("%d", &e), e) {
        unordered_map<int, vi> g;
        while(e--) {
            scanf("%d %d", &i, &j);
            g[i].pb(j);
            g[j].pb(i);
        }

        int s, ttl, count;
        while(scanf("%d %d", &s, &ttl), (s || ttl)) {
            unordered_map<int, int> vis;
            for(auto i : g) {
                vis[i.first] = 0;
            }
            queue<int> q;
            q.push(s);
            vis[s] = 1;
            count = 1;
            int ttl_copy = ttl;
            while(!q.empty() && ttl) {
                int q_size = q.size();
                forn(i, 0, q_size - 1) {
                    int popped = q.front();
                    q.pop();
                    for(int neigh : g[popped]) {
                        if(!vis[neigh]) {
                            vis[neigh] = 1;
                            count++;
                            q.push(neigh);
                        }
                    }
                }
                ttl--;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", c++, g.size() - count, s, ttl_copy);
        }
    }
    return 0;
}