#include <bits/stdc++.h>
using namespace std;

/*
    This is a minimum spanning tree problem where the cost of the edges is implicit
    in the form of euclidean distance between the given freckle coordinates.

    Once you form an edge list after computing the edge costs, it becomes a 
    straight-forward MST problem.
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

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

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
        int p1 = findSet(i), p2 = findSet(j);
        if(r[p1] > r[p2]) {
            p[p2] = p1;
        } else {
            p[p1] = p2;
            if(r[p1] == r[p2])
                r[p2]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, num_pt;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &num_pt);
        vector<pair<double, double>> pts(num_pt);
        forn(i, 0, num_pt - 1) {
            scanf("%lf %lf", &pts[i].first, &pts[i].second);
        }
        vector<pair<double, ii>> edge_list;
        forn(i, 0, num_pt - 1) {
            forn(j, i + 1, num_pt - 1) {
                edge_list.pb(make_pair(dist(pts[i], pts[j]), make_pair(i, j)));            }
        } 
        sort(edge_list.begin(), edge_list.end());

        UnionFind uf(num_pt);
        double min_cost = 0;
        forn(i, 0, edge_list.size() - 1) {
            pair<double, ii> edge = edge_list[i];
            if(!uf.isSameSet(edge.second.first, edge.second.second)) {
                uf.unionSet(edge.second.first, edge.second.second);
                min_cost += edge.first;
            }
        }
        printf("%.2lf\n", min_cost);
        if(t)
            puts("");
    }
    return 0;
}