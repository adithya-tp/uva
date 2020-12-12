#include <bits/stdc++.h>
using namespace std;

/*
    Finding low cost internet lines between the cities in the context of this question
    is exactly the minimum spanning tree problem. 
    
    Use Kruskal's algorithm, wherein the edges are sampled from a sorted edge list
    and the cycle check is done using the union find / disjoint set data structure.
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
    vi p, rank;
    int num_comps;
public:
    UnionFind(int V) {
        rank.assign(V, 0);
        forn(i, 0, V - 1) {
            p.pb(i);
        }
        num_comps = V;
    }
    // findSet with Path Compression
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int p1 = findSet(i), p2 = findSet(j);
            if(rank[p1] > rank[p2]) {
                p[p2] = p1;
            } else {
                p[p1] = p2;
                if(rank[p1] == rank[p2])
                    rank[p2]++;
            }
            num_comps--;
        }
    }

    int getCC() {
        return num_comps;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char buf[30];
    char c1_buf[10], c2_buf[10];
    string c1, c2;
    int t, v, e, w;
    scanf("%d", &t);
    // Skip over the endline character after getting t [test_cases]
    while(getchar() != '\n');
    // Skip over the blank line before the first test case
    gets(buf);
    while(t--) {
        int mapping = 0;
        scanf("%d", &v);
        scanf("%d", &e);
        unordered_map<string, int> city2idx;
        vector<pair<int, ii>> edge_list;
        forn(i, 0, e - 1) {
            scanf("%s %s %d", c1_buf, c2_buf, &w);
            c1 = c1_buf;
            c2 = c2_buf;
            
            if(city2idx.find(c1) == city2idx.end()) {
                city2idx[c1] = mapping++;
            }
            if(city2idx.find(c2) == city2idx.end()) {
                city2idx[c2] = mapping++;
            }
            edge_list.pb(make_pair(w, ii(city2idx[c1], city2idx[c2])));
        }
        sort(edge_list.begin(), edge_list.end());

        int min_cost = 0;
        UnionFind uf(v);
        forn(i, 0, e - 1) {
            pair<int, ii> edge = edge_list[i];
            if(!uf.isSameSet(edge.second.first, edge.second.second)) {
                min_cost += edge.first;
                uf.unionSet(edge.second.first, edge.second.second);
            }
        }
        printf("%d\n", min_cost);
        if(t)
            puts("");
    }
    return 0;
}