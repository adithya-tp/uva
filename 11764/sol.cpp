#include <bits/stdc++.h>
using namespace std;

/*
    A linear scan to keep track of all high and low jumps (ignore equal jumps).
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, low, high, num_walls, c = 1;
    cin >> t;
    while(t--) {
        low = 0, high = 0;
        cin >> num_walls;
        vi h(num_walls);
        forn(i, 0, num_walls - 1)
            cin >> h[i];
        forn(i, 0, num_walls - 2) {
            if(h[i] < h[i + 1])
                high++;
            else if(h[i] > h[i + 1])
                low++;
        }
        cout << "Case " << c++ << ": " << high << " " << low << "\n";
    }
    return 0;
}