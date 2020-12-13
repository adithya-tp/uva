#include <bits/stdc++.h>
using namespace std;

/*
    Use the Union Find Disjoint Set data structure to efficiently
    perform 'c' queries (unite the disjoint sets that c1 and c2 belong to, if they aren't already) and
    answer 'q' queries (to query if both computers belong to the same disjoint set).
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
                if(r[p1] == r[p2]) {
                    r[p2]++; 
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    char buf[20];
    cin.tie(0);
    int t;
    scanf("%d", &t);
    while(getchar() != '\n');
    gets(buf);

    int v, c1, c2;
    char type;
    while(t--) {
        scanf("%d", &v);
        while(getchar() != '\n');
        UnionFind uf(v);
        int success = 0, not_success = 0;
        while(gets(buf) && buf[0]) {
            sscanf(buf, "%c %d %d", &type, &c1, &c2);
            if(type == 'c') {
                uf.unionSet(c1 - 1, c2 - 1);
            } else {
                if(uf.isSameSet(c1 - 1, c2 - 1))
                    success++;
                else
                    not_success++;
            }
        }

        printf("%d,%d\n", success, not_success);
        if(t)
            printf("\n");
    }
    return 0;
}