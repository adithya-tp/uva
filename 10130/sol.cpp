#include <bits/stdc++.h>
using namespace std;

/*
    Knapsack problem where you add up the maximum value of each person in a given group.
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
    int t, n, g, cap;
    cin >> t;
    while(t--) {
        cin >> n;
        vi w(n), v(n);
        forn(i, 0, n - 1) {
            cin >> v[i] >> w[i];
        }
        int total = 0;
        cin >> g;
        forn(i, 0, g - 1) {
            cin >> cap;
            int t[n + 1][cap + 1];
            memset(t, 0, sizeof t);
            forn(j, 1, n) {
                forn(k, 1, cap) {
                    if(w[j - 1] <= k) {
                        t[j][k] = max(t[j - 1][k], v[j - 1] + t[j - 1][k - w[j - 1]]);
                    } else {
                        t[j][k] = t[j - 1][k];
                    }
                }
            }
            total += t[n][cap];
        }
        cout << total << "\n";
    }
    return 0;
}