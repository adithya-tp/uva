#include <bits/stdc++.h>
using namespace std;

/*
    Augment the Union Find data structure with an "amount" vector.
    Basically the total amount (owe + owed) in each disjoint set must be zero.
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
    vi p, amt;
    set<int> parents;
public:
    UnionFind(int v) {
        forn(i, 0, v - 1) {
            p.pb(i);
            parents.insert(i);
        }
    }
    void assign_amounts(vector<int>& v) {
        for(int i : v)
            amt.pb(i);
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
            p[p2] = p1;
            amt[p1] += amt[p2];
            parents.erase(p2);
        }
    }
    bool isPossible() {
        for(int i : parents) {
            if(amt[i])
                return false;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, e;
    cin >> t;
    while(t--) {
        cin >> n >> e;
        vi amt(n);
        UnionFind uf(n);
        forn(i, 0, n - 1) {
            cin >> amt[i];
        }
        uf.assign_amounts(amt);
        int a, b;
        forn(i, 0, e - 1) {
            cin >> a >> b;
            uf.unionSet(a, b);
        }
        if(uf.isPossible()) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }

    }
    return 0;
}