#include <bits/stdc++.h>
using namespace std;

/*
    Maintain a map to lookup values and check if a subject exists.
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
    int t, d, n, c = 1;
    string s;
    cin >> t;
    while(t--) {
        cin >> d;
        unordered_map<string, int> m;
        while(d--) {
            cin >> s;
            cin >> m[s];
        }
        cin >> d >> s;
        cout << "Case " << c++ << ": ";
        if(m.find(s) == m.end() || m[s] > d + 5)
            cout << "Do your own homework!\n";
        else if(m[s] <= d)
            cout << "Yesss\n";
        else
            cout << "Late\n";
            
    }
    return 0;
}