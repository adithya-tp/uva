#include <bits/stdc++.h>
using namespace std;

/*
    The difficult bit is to identify this as a minimum spanning tree problem.
    
    The code to parse the input into a edge list would be something to watch out for.
    Once that's done, print out the edges of the minimum spanning tree as you see them, while
    checking for cycles using the union find / disjoint set data structure.
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
        return p[i] == i ? i : (p[i] = findSet(p[i]));
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
    int t, v;
    char buf[1000];
    scanf("%d", &t);
    int c = 1;
    while(t--) {
        scanf("%d", &v);
        while(getchar() != '\n');
        UnionFind uf(v);
        vector<pair<int, ii>> edge_list;

        int w;
        char comma;
        forn(i, 0, v - 1) {
            forn(j, 0, v - 1) {
                scanf("%d%c", &w, &comma);
                if(i < j && w) {
                    edge_list.pb(make_pair(w, make_pair(i, j)));
                }
            }
        }

        sort(edge_list.begin(), edge_list.end());
        int e = edge_list.size();

        printf("Case %d:\n", c++);
        forn(i, 0, e - 1) {
            pair<int, ii> edge = edge_list[i];
            if(!uf.isSameSet(edge.second.first, edge.second.second)) {
                uf.unionSet(edge.second.first, edge.second.second);
                printf("%c-%c %d\n", char(edge.second.first + 65), char(edge.second.second + 65), edge.first);
            }
        }
    }
    return 0;
}