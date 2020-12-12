#include <bits/stdc++.h>
using namespace std;

/*
    Do a floodfill dfs from the given coordinate for all '0's (water)
    while keeping track of the number of '0's you've seen along the way.
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

vi dr = {1, 0, -1, 0};
vi dc = {0, 1, 0, -1};
char g[105][105];
int n, m;

int dfs(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m || g[r][c] != '0') return 0;
    g[r][c] = 'x';
    int ans = 1;
    for(int i = 0; i < 4; i++) {
        ans += dfs(r + dr[i], c + dc[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, x, y;
    scanf("%d", &t);
    /* 
        To skip the newline after getting the integer. 
        Alternatively, the previous line could've been scanf("%d "&t); [extra space]
    */
    while(getchar() != '\n');
    // To skip the blank line before the first test case
    gets(g[0]);
    while(t--) {
        gets(g[0]);
        sscanf(g[0], "%d %d", &x, &y);
        n = 0, m;
        // g[n][0] checks if I've encountered a blank line
        while(gets(g[n]) && g[n][0]) {
            n++;
        }
        m = strlen(g[0]);
        printf("%d\n", dfs(x - 1, y - 1));
        if(t)
            puts("");
    }
    return 0;
}