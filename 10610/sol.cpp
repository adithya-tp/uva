#include <bits/stdc++.h>
using namespace std;

/*
    Construct a graph using the given gopher hole coordinates as vertices
    if the gopher holes are close enough. Two gopher holes are close enough
    if their euclidean distance it not greater than v * m * 60 meters.

    After this graph is constructed, we can simply check for a path from from
    point 0 to point 1, while keeping track of distance.
*/

#define MAXN 1010
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

double x[MAXN], y[MAXN];
double max_dis;

bool canMakeIt(int i, int j) {
    double dis = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    return dis <= max_dis;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, m;
    char buf[100];
    while(scanf("%d %d", &v, &m), (v || m)) {
        max_dis = v * m * 60.0;
        // To consume the new line that comes after the first scanf
        gets(buf);
        int pts = 0;
        // Keep reading in string containing coordinates
        while(gets(buf)) {
            // until you encounter a blank line.
            if(strlen(buf) == 0) break;
            // Gather the coordinates into their respective global arrays
            sscanf(buf, "%lf %lf", &x[pts], &y[pts]);
            // Variable to keep track of number of points for given test case
            pts++;
        }

        // Construct graph out of given (x, y) coordinates.
        unordered_map<int, vi> g;
        forn(i, 0, pts - 2) {
            forn(j, i + 1, pts - 1) {
                // Make an edge between two coordinates only if they are close enough.
                if(canMakeIt(i, j)) {
                    g[i].pb(j);
                    g[j].pb(i);
                }
            }
        }

        queue<int> q;
        q.push(0);
        vi d(pts, -1);
        while(!q.empty()) {
            int popped = q.front();
            q.pop();
            if(popped == 1)
                break;
            for(int n : g[popped]) {
                if(d[n] == -1) {
                    q.push(n);
                    d[n] = d[popped] + 1;
                }
            }
        }
        if(d[1] == -1)
            printf("No.\n");
        else
            printf("Yes, visiting %d other holes.\n", d[1]);
    }
    return 0;
}