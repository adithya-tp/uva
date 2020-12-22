#include <bits/stdc++.h>
using namespace std;

/*
    
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

int memo[10100];
int max_bet;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n, n) {
        max_bet = INT_MIN;
        vi v(n);
        forn(i, 0, n - 1)
            cin >> v[i];
        memset(memo, 0, sizeof(memo));
        memo[0] = v[0];
        forn(i, 1, n - 1) {
            memo[i] = max(memo[i - 1] + v[i], v[i]);
            max_bet = max(max_bet, memo[i]);
        }
        if(max_bet <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << max_bet << ".\n";
    }
    return 0;
}