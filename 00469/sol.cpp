#include <bits/stdc++.h>
using namespace std;

/*
    Flood fill algorithm with dfs. 
    Keep counting the number of connected cells with 'W' and replace them
    with some other character so you don't visit it again. 
    
    Oh, and send in a copy of the graph for different queries on the same
    graph. And print blank lines only BETWEEN test cases, and not after the 
    last one. UVA a stickler for presentation lyk dat.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vcc;

vi dr = {1, 1, 0, -1, -1, -1, 0, 1};
vi dc = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(int r, int c, char c1, char c2, vcc& g) {
    if(r < 0 || r >= g.size() || c < 0 || c >= g[0].size()) return 0;
    else if(g[r][c] != c1) return  0;
    int ans = 1;
    g[r][c] = c2;
    for(int i = 0; i < 8; i++) {
        ans += floodfill(r + dr[i], c + dc[i], c1, c2, g);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, x, y, m, n;
    string s;
    getline(cin, s);
    t = stoi(s);
    getline(cin, s);
    int c = 0;
    while(t--) {
        vcc g;
        if(c) {
            printf("\n");
        }
        c++;
        while(getline(cin, s)) {
            if(!s.size())
                break;
            if(isalpha(s[0])) {
                vc line(s.begin(), s.end());
                g.push_back(line);
            } else {
                vcc copy = g;
                vi xy;
                string coord;
                stringstream ss(s);
                while(getline(ss, coord, ' ')) {
                    xy.pb(stoi(coord));
                }
                printf("%d\n", floodfill(xy[0] - 1, xy[1] - 1, 'W', '.', copy));
            }
        }
    }
    return 0;
}