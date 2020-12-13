#include <bits/stdc++.h>
using namespace std;

/*
    Keep track of the number of connected components using the
    Union Find data structure.

    You could also construct the graph and find the number of 
    connected components with dfs or bfs.
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
    vi p, r;
    int cc;
public:
    UnionFind(int v) {
        r.assign(v, 0);
        forn(i, 0, v - 1)
            p.pb(i);
        cc = v;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool sameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    int getCC() {
        return cc;
    }
    void unionSet(int i, int j) {
        if(!sameSet(i, j)) {
            int p1 = p[i], p2 = p[j];
            if(r[p1] > r[p2]) {
                p[p2] = p1;
            } else {
                p[p1] = p2;
                if(r[p1] == r[p2])
                    r[p2]++;
            }
            cc--;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e, i, j;
    int c = 1;
    while(scanf("%d %d", &n, &e), (n || e)) {
        UnionFind uf(n);
        while(e--) {
            scanf("%d %d", &i, &j);
            uf.unionSet(i, j);
        }
        printf("Case %d: %d\n", c++, uf.getCC());
    }
    return 0;
}