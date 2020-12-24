#include <bits/stdc++.h>
using namespace std;

/*
    Run BFS while maintaining a parent map to trace out the path later.
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
    int t;
    string s, a, b;
    int c = 0;
    while(getline(cin, s)) {
        if(c)
            cout << "\n";
        c = 1;
        t = stoi(s);
        unordered_map<string, vector<string>> g;
        unordered_map<string, string> p;
        forn(i, 0, t) {
            getline(cin, s);
            stringstream ss(s);
            ss >> a >> b;
            if(i != t) {
                g[a].pb(b);
                g[b].pb(a);
                p[a] = "#";
                p[b] = "#";
            }
        }
        getline(cin, s);
        if(g.find(a) == g.end() || g.find(b) == g.end()) {
            cout << "No route\n";
            continue;
        }

        unordered_map<string, bool> vis;
        queue<string> q;
        q.push(a);
        vis[a] = true;
        while(!q.empty()) {
            string popped = q.front();
            q.pop();
            if(popped == b)
                break;
            for(string neigh : g[popped]) {
                if(!vis[neigh]) {
                    vis[neigh] = true;
                    p[neigh] = popped;
                    q.push(neigh);
                }
            }
        }

        if(p[b] == "#") {
            cout << "No route\n";
        } else {
            string path;
            while(b != a) {
                path = p[b] + " " + b + "\n" + path;
                b = p[b];
            }
            cout << path;
        }
    }
    return 0;
}