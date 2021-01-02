#include <bits/stdc++.h>
using namespace std;

/*
    We've got two different cases: a > b and a <= b. (a >= b and a < b is also valid).
    Find the number of clicks in both directions for each of these cases print the
    minimum value.
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
    int a, b, ans;
    while(cin >> a >> b, a != -1 && b != -1) {
        
        if(b > a) {
            ans = min(b - a, (99 - b) + a + 1);
        } else {
            ans = min(a - b, (99 - a) + b + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}