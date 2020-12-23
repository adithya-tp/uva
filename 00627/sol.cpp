#include <bits/stdc++.h>
using namespace std;

/*
    Parsing the input is more of a pain than running bfs.
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
    int t, a, b;
    regex hyphen("-");
    regex comma(",");
    string s, query;
    while(getline(cin, s)) {
        cout << "-----\n";
        t = stoi(s);
        unordered_map<int, vi> g;
        while(t--) {
            getline(cin, s);
            vector<string> g_line(sregex_token_iterator(s.begin(), s.end(), hyphen, -1), sregex_token_iterator());
            a = stoi(g_line[0]);
            if(g_line.size() > 1) {
                vector<string> nbrs(sregex_token_iterator(g_line[1].begin(), g_line[1].end(), comma, -1), sregex_token_iterator());
                for(string item : nbrs) {
                    g[a].pb(stoi(item));
                }
            } else {
                g[a] = {};
            }
        }

        getline(cin, s);
        t = stoi(s);
        while(t--) {
            getline(cin, s);
            stringstream ss(s);
            ss >> query;
            a = stoi(query);
            ss >> query;
            b = stoi(query);
            
            unordered_map<int, int> p, vis;
            for(auto i : g) {
                p[i.first] = -1;
            }

            queue<int> q;
            q.push(a);
            vis[a] = true;
            while(!q.empty()) {
                int popped = q.front();
                if(popped == b) {
                    break;
                }
                q.pop();
                for(int n : g[popped]) {
                    if(!vis[n]) {
                        vis[n] = true;
                        p[n] = popped;
                        q.push(n);
                    }
                }
            }
            if(p[b] == -1)
                cout << "connection impossible\n";
            else {
                int x = b;
                string path = to_string(x);
                while(x != a) {
                    x = p[x];
                    path = to_string(x) + " " + path;
                }
                cout << path << "\n";
            }
        }
    }
    return 0;
}