#include <bits/stdc++.h>
using namespace std;

/*
    Kept track of coordinates and the step where I encountered them with
    a unordered_map that uses a custom hash.

    Personally, assigning the right direction in terms of rows and columns
    of the matrix rather than thinking in terms of the normal coordinate graph
    was important to solving this.
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

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<char, ii> dirs = {
        {'N', {-1, 0}},
        {'W', {0, -1}},
        {'S', {1, 0}},
        {'E', {0, 1}}
    };
    int m, n, x, y, steps;
    string s;
    while(cin >> m >> n >> y) {
        if(!(m || n || y))
            break;
        int loop = 0;
        unordered_map<ii, int, hash_pair> coords;
        y--;
        x = 0;
        steps = 0;
        vvc g;
        forn(i, 1, m) {
            cin >> s;
            vc line(s.begin(), s.end());
            g.pb(line);
        }
        while(!(x < 0 || x >= m || y < 0 || y >= n)) {
            if(coords.find(make_pair(x, y)) != coords.end()) {
                loop = steps - coords[make_pair(x, y)];
                break;
            }
            coords[make_pair(x, y)] = steps;
            steps++;
            ii dir = dirs[g[x][y]];
            x += dir.first;
            y += dir.second;
        }
        
        if(loop) {
            cout << steps - loop << " step(s) before a loop of " << loop << " step(s)\n";
        } else {
            cout << steps << " step(s) to exit\n";
        }
    }
    return 0;
}