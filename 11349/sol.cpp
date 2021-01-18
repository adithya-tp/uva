#include <bits/stdc++.h>
using namespace std;

/*
    Each element in the matrix needs to be non-negative and same as v[n - i - 1][n - j - 1]
    where i, j are the row and column indices of an element. You can also stop checking
    once you reach the middle row.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
#define x real()
#define y imag()
#define M_PI 3.14159265358979323846
typedef double T;
typedef complex<T> pt;
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
    int t, n, c = 1;
    cin >> t;
    string junk;
    while(t--) {
        cin >> junk >> junk >> n;
        vector<vector<ll>> v(n, vector<ll>(n));
        forn(i, 0, n - 1) {
            forn(j, 0, n - 1) {
                cin >> v[i][j];
            }
        }

        bool sym = true;
        forn(i, 0, n / 2) {
            forn(j, 0, n - 1) {
                if(v[i][j] != v[n - i - 1][n - j - 1] || v[i][j] < 0) {
                    sym = false;
                    break;
                }
            }
        }
        cout << "Test #" << c++ << ": ";
        if(sym) {
            cout << "Symmetric.\n";
        } else {
            cout << "Non-symmetric.\n";
        }
    }
    return 0;
}