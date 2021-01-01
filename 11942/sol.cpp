#include <bits/stdc++.h>
using namespace std;

/*
    Copy over the sequence and sort it (both ways). Check if either matches with the original vector.
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
    int t;
    cin >> t;
    cout << "Lumberjacks:\n";
    while(t--) {
        vi v(10), c(10);
        forn(i, 0, 10 - 1)
            cin >> v[i];
        
        c = v;
        sort(c.begin(), c.end());
        bool order = true;
        forn(i, 0, 10 - 1) {
            if(v[i] != c[i]) {
                order = false;
                break;
            }
        }

        if(!order) {
            order = true;
            reverse(c.begin(), c.end());
            forn(i, 0, 10 - 1) {
                if(v[i] != c[i]) {
                    order = false;
                    break;
                }
            }
        }

        if(order) {
            cout << "Ordered\n";
        } else {
            cout << "Unordered\n";
        }
    }

    return 0;
}