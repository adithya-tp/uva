#include <bits/stdc++.h>
using namespace std;

/*
    Using (budget, garment_type) as our dp state, find transitions that make certain states valid or
    invalid and memoize the values that are arrived at. We use atmost 20 steps to compute the value of a state
    (since each garment has atmost 20 options). And since we have a total of M x C states (200 x 20 states),
    the complexity of this algorithm is O(k * M * C)
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

int t, m, c;


// For atmost C = 20 garments each of which have atmost k = 20 options
int prices[20][21];
// To store the values of all possible (budget, garment type) states
int memo[200][20];;

int top_dp(int curr_m, int g) {
    if(curr_m < 0) return INT_MIN;
    if(g == c) return m - curr_m;
    if(memo[curr_m][g] != -1) return memo[curr_m][g];
    int ans = -1;
    forn(i, 1, prices[g][0]) {
        ans = max(ans, top_dp(curr_m - prices[g][i], g + 1));
    }
    return memo[curr_m][g] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> m >> c;
        forn(i, 0, c - 1) {
            cin >> prices[i][0];
            forn(j, 1, prices[i][0]) {
                cin >> prices[i][j];
            }
        }
        memset(memo, -1, sizeof memo);
        int max_spent = top_dp(m, 0);
        if(max_spent < 0)
            cout << "no solution\n";
        else
            cout << max_spent << "\n";
    }
    return 0;
}