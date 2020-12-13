#include <bits/stdc++.h>
using namespace std;

/*
    Use the Union Find data structure to unite the disjoint sets of
    v students. For each adjacent pair of students in the input groups, 
    unify them if they're not already in the same disjoint set.

    At the end, you can just iterate through the v students, and
    count the number of students in the same disjoint set as 0.
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
public:
    UnionFind(int v) {
        r.assign(v, 0);
        forn(i, 0, v - 1)
            p.pb(i);
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int p1 = findSet(i), p2 = findSet(j);
            if(r[p1] > r[p2]) {
                p[p2] = p1;
            } else {
                p[p1] = p2;
                if(r[p1] == r[p2])
                    r[p2]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, e, k;
    while(scanf("%d %d", &v, &e), (v || e)) {
        UnionFind uf(v);
        while(e--) {
            scanf("%d", &k);
            vi v(k);
            forn(i, 0, k - 1) {
                scanf("%d", &v[i]);
            }
            forn(i, 0, k - 2) {
                uf.unionSet(v[i], v[i + 1]);
            }
        }
        int count = 1;
        forn(i, 1, v - 1) {
            if(uf.isSameSet(i, 0))
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}