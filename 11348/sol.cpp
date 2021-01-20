#include <bits/stdc++.h>
using namespace std;

/*
    Keep track of all the stamps that belong to one person alone using
    a map and set.
    Use the resulting map to count the number of unique stamps belonging
    to each of the friends and then print out this fraction as a percentage.
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
    int t, n, num, typ, c = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        unordered_map<int, int> t2f;
        set<int> exclude;
        forn(i, 0, n - 1) {
            cin >> num;
            while(num--) {
                cin >> typ;
                if(t2f.find(typ) != t2f.end() && t2f[typ] != i) {
                    t2f.erase(typ);
                    exclude.insert(typ);
                } else if(exclude.find(typ) != exclude.end()) {
                    continue;
                } else {
                    t2f[typ] = i;
                }
            }
        }
        vi v(n);
        for(auto i : t2f) {
            v[i.second]++;
        }
        cout << "Case " << c++ << ":"; 
        for(auto i : v) {
           cout << " " << fixed << setprecision(6) << double(i) / t2f.size() * 100.0 << "%";
        }
        cout << "\n";
    }
    return 0;
}