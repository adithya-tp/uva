#include <bits/stdc++.h>
using namespace std;

/*
    Floodfill while keeping track of the largest connected component seen so far.
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

char g[30][30];
int n, m;

vi dr = {1, 1, 0, -1, -1, -1, 0, 1};
vi dc = {0, 1, 1, 1, 0, -1, -1, -1};

int dfs(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m || (g[r][c] == '0')) return 0;
    g[r][c] = '0';
    int ans = 1;
    for(int i = 0; i < 8; i++) {
        ans += dfs(r + dr[i], c + dc[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    char buf[30];
    scanf("%d", &t);
    while(getchar() != '\n');
    gets(buf);
    while(t--) {
        int max_size = 0;
        n = 0;
        while(gets(g[n]) && g[n][0]) {
            n++;
        }
        m = strlen(g[0]);
        forn(i, 0, n - 1) {
            forn(j, 0, m - 1) {
                if(g[i][j] == '1') {
                    max_size = max(max_size, dfs(i, j));
                }
            }
        }
        printf("%d\n", max_size);
        if(t)
            puts("");
    }
    return 0;
}