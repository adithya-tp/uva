#include <bits/stdc++.h>
using namespace std;

/*
    Augment the Union Find Data structure with a set that
    keeps track of all current representative elements of
    disjoint sets.

    Adding a extra function to your union find implementation
    to return the number of trees and acorns would be helpful
    when solving this problem.
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
    set<int> last;
public:
    UnionFind(int v) {
        s.assign(v, 1);
        forn(i, 0, v - 1) {
            p.pb(i);
            last.insert(i);
        }
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
            if(s[p1] > s[p2]) {
                p[p2] = p1;
                last.erase(p2);
            } else {
                last.erase(p1);
                p[p1] = p2;
                if(s[p1] == s[p2])
                    s[p2]++;
            }
        }
    }
    pair<int, int> getTreesAndAcorns() {
        ii ans;
        for(int i : last) {
            if(s[i] == 1) {
                ans.second++;
            } else {
                ans.first++;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    while(t--) {
        vector<pair<char, char>> edges;
        while(true) {
            cin >> s;
            if(s[0] == '*')
                break;
            edges.pb(make_pair(s[1], s[3]));
        }
        cin >> s;
        int i = 0;
        unordered_map<char, int> v2i;
        for(char c : s) {
            if(isalpha(c)) {
                v2i[c] = i++;
            }
        }
        UnionFind uf(v2i.size());
        for(ii p : edges) {
            uf.unionSet(v2i[p.first], v2i[p.second]);
        }
        ii ans = uf.getTreesAndAcorns();
        cout << "There are " << ans.first << " tree(s) and " << ans.second << " acorn(s).\n";
    }
    return 0;
}