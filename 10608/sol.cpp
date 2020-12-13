#include <bits/stdc++.h>
using namespace std;

/*
    Use size as a heuristic when combining disjoint sets in a 
    Union Find and keep updating the size of the unified
    disjoint sets at tht index of the representative element
    for that set.
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
    int max_size;
public:
    UnionFind(int v) {
        s.assign(v, 1);
        forn(i, 0, v - 1)
            p.pb(i);
        max_size = 1;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int p1 = p[i], p2 = p[j];
            if(s[p1] > s[p2]) {
                s[p1] += s[p2];
                p[p2] = p1;
                max_size = max(s[p1], max_size);
            } else {
                s[p2] += s[p1];
                p[p1] = p2;
                max_size = max(s[p2], max_size);
            }
        }
    }
    int getMaxSize() {
        return max_size;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, e, i, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &e);
        UnionFind uf(n);
        while(e--) {
            scanf("%d %d", &i, &j);
            uf.unionSet(i - 1, j - 1);
        }
        printf("%d\n", uf.getMaxSize());
    }
    return 0;
}