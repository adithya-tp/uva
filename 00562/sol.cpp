#include <bits/stdc++.h>
using namespace std;

/*
    A variant of knapsack, where we use the knapsack answer to find the 
    minimum difference asked in the problem.
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
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vi v(n);
        int sum = 0;
        forn(i, 0, n - 1) {
            cin >> v[i];
            sum += v[i];
        }

        int t[n + 1][sum + 1];
        memset(t, 0, sizeof t);
        int min_diff = sum;
        forn(i, 1, n) {
            forn(j, 1, sum) {
                if(v[i - 1] <= j) {
                    t[i][j] = max(t[i - 1][j], v[i - 1] + t[i - 1][j - v[i - 1]]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
                int other = sum - t[i][j];
                min_diff = min(min_diff, abs(t[i][j] - other));
            }
        }
        cout << min_diff << "\n";
    }
    return 0;
}