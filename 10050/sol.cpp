#include <bits/stdc++.h>
using namespace std;

/*
    Use a bitset array to keep track of which working days is predicted to be a hartal.
    Set every p_i th value to 1 for each party. At the end, simply take the sum of elements
    in the bitset array upto the given number of days.
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
    int t, d, p, in;
    cin >> t;
    while(t--) {
        cin >> d;
        bitset<3651> b;
        cin >> p;
        while(p--) {
            cin >> in;
            for(int i = in; i <= d; i += in) {
                if(i % 7 == 6 || i % 7 == 0)
                    continue;
                b[i] = true;
            }
        }
        
        int ans = 0;
        forn(i, 1, d)
            ans += b[i];
        cout << ans << "\n";
    }
    return 0;
}