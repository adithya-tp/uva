#include <bits/stdc++.h>
using namespace std;

/*
    Use Union Find to return the size of the bigger disjoint set
    whenever you unite two disjoint sets for each new friendship.
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

class UnionFind {
private:
    vi p, s;
public:
    UnionFind(int v) {
        s.assign(v, 1);
        forn(i, 0, v - 1) {
            p.pb(i);
        }
    }
    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    int unionSet(int i, int j) {
        int p1 = findSet(i), p2 = findSet(j);
        if(p1 != p2) {
            p[p2] = p1;
            s[p1] += s[p2];
        }
        return s[p1];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int id = 0;
        vector<ii> edges;
        unordered_map<string, int> s2i;
        int e;
        cin >> e;
        string a, b;
        forn(i, 0, e - 1) {
            cin >> a >> b;
            if(s2i.find(a) == s2i.end()) {
                s2i[a] = id++;
            }

            if(s2i.find(b) == s2i.end()) {
                s2i[b] = id++;
            }
            edges.pb(make_pair(s2i[a], s2i[b]));
        }
        
        UnionFind uf(id);
        for(ii edge : edges) {
            cout << uf.unionSet(edge.first, edge.second) << "\n";
        }
    }
    return 0;
}