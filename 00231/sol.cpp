#include <bits/stdc++.h>
using namespace std;

/*
    This problem boils down to finding the longet non-increasing subsequence.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
inline istream& skip_endl(istream &is) { return is.ignore(numeric_limits<streamsize>::max(),'\n'); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c = 1;
    while(cin >> n, n != -1) {
        if(c - 1)
            cout << "\n";
        vi v = {n};
        while(cin >> n, n != -1) {
            v.pb(n);
        }
        int max_missiles = 1;
        vi memo(v.size(), 1);
        forn(i, 1, v.size() - 1) {
            forn(j, 0, i - 1) {
                if(v[j] >= v[i]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
            max_missiles = max(max_missiles, memo[i]);
        }
        cout << "Test #" << c++ << ":\n  maximum possible interceptions: " << max_missiles << "\n";
    }
    return 0;
}