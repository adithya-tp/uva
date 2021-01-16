#include <bits/stdc++.h>
using namespace std;

/*
    This problem becomes easy with the 'next_permutation' utility in STL.
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
    string s;
    while(cin >> s) {
        if(s == "#") break;
        if(next_permutation(s.begin(), s.end())) {
            cout << s << "\n";
        } else {
            cout << "No Successor\n";
        }
    }
    return 0;
}