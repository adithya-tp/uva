#include <bits/stdc++.h>
using namespace std;

/*
    Keep track of all directions seen so far as a vector of +1 and -1(s).
    
    If the direction isn't left or right, simply use the direction at the appropriate
    index to update your position. Don't forget to add this command that you looked up
    to the "directions" vector.
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
    int t, d;
    string s;
    cin >> t;
    regex num("[0-9]+");
    while(t--) {
        cin >> d;
        vi dirs;
        int pos = 0;
        forn(i, 0, d - 1) {
            cin >> s;
            if(s == "LEFT") {
                pos--;
                dirs.pb(-1);
            } else if(s == "RIGHT") {
                pos++;
                dirs.pb(1);
            } else {
                int idx;
                cin >> s >> idx;
                dirs.pb(dirs[idx - 1]);
                pos += dirs[i];
            }
        }
        cout << pos << "\n";
    }
    return 0;
}