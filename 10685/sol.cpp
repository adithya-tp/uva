#include <bits/stdc++.h>
using namespace std;

/*
    Use Union Find to keep track of the largest chain.
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
    vi p, sz;
    int largest = 1;
public:
    UnionFind(int v) {
        sz.assign(v, 1);
        forn(i, 0, v - 1) {
            p.pb(i);
        }
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void UnionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int p1 = findSet(i), p2 = findSet(j);
            p[p2] = p1;
            sz[p1] += sz[p2];
            largest = max(largest, sz[p1]);
        }
    }
    int getLargest() {
        return largest;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c, r;
    while(cin >> c >> r, c || r) {
        string s, a, b;
        unordered_map<string, int> s2i;
        forn(i, 0, c - 1) {
            cin >> s;
            s2i[s] = i;
        }

        UnionFind uf(c);
        forn(i, 0, r - 1) {
            cin >> a >> b;
            uf.UnionSet(s2i[a], s2i[b]);
        }
        cout << uf.getLargest() << "\n";

    }
    return 0;
}