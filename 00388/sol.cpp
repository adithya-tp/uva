#include <bits/stdc++.h>
using namespace std;

/*
    Run a BFS from each planet in the galaxy while keeping track of the value of
    its commodity till it reaches earth. If at each successive level, earth is not
    one of the neighbors, the commodities value depreciates by 5% of its current value.

    The planet whose commodity has the highest value after reaching earth, and is
    lexicographically first is the answer.
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
    int n;
    char u;
    double val;
    string neigh;
    while(cin >> n) {
        unordered_map<char, vc> g;
        unordered_map<char, double> vals;
        forn(i, 0, n - 1) {
            cin >> u >> val;
            vals[u] = val;
            cin >> neigh;
            for(char c : neigh) {
                g[u].pb(c);
                if(c != '*')
                    g[c].pb(u);
            }
        }   

        double max_val = 0.0;
        char max_planet = 'z';
        for(auto item : g) {
            queue<char> q;
            q.push(item.first);
            unordered_map<char, bool> vis;
            bool arrived = false;
            double curr_val = vals[item.first];
            while(!q.empty() && !arrived) {
                int q_size = q.size();
                forn(i, 0, q_size - 1) {
                    char popped = q.front();
                    q.pop();
                    for(char nei : g[popped]) {
                        if(nei == '*') {
                            arrived = true;
                            break;
                        } else {
                            if(!vis[nei]) {
                                vis[nei] = true;
                                q.push(nei);
                            }
                        }
                    }
                    if(arrived)
                        break;
                }
                curr_val *= 0.95;
            }
            if(curr_val >= max_val) {
                if(curr_val == max_val)
                    max_planet = min(max_planet, item.first);
                else
                    max_planet = item.first;
                max_val = curr_val;
            }
        }
        cout << "Import from " << max_planet << "\n";
    }
    return 0;
}