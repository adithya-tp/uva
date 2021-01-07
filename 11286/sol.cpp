#include <bits/stdc++.h>
using namespace std;

/*
    Sort the given combination of courses, join them together as the key to keep track
    of the popular combo.
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
    int t;
    while(cin >> t, t) {
        unordered_map<string, int> counts;
        int max_count = 0;
        while(t--) {
            vi v(5);
            string s;
            forn(i, 0, 4) {
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            stringstream ss;
            for(auto i : v) {
                ss << to_string(i);
            }
            
            max_count = max(max_count, ++counts[ss.str()]);
        }
        int num_maxes = 0;
        for(auto i : counts) {
            if(i.second == max_count)
                num_maxes+= max_count;
        }
        cout << num_maxes << "\n";
    }
    return 0;
}