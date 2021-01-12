#include <bits/stdc++.h>
using namespace std;

/*
    
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
    int n;
    while(cin >> n) {
        vi v(n);
        set<int> d;
        forn(i, 0, n - 1) {
            cin >> v[i];
            if(i != n - 1)
                d.insert(i + 1);
        }
        if(n == 1) {
            cout << "Jolly\n";
            continue;
        }
        forn(i, 0, v.size() - 2) {
            int diff = abs(v[i + 1] - v[i]);
            if(d.find(diff) != d.end())
                d.erase(diff);
        }
        if(d.size())
            cout << "Not jolly\n";
        else
            cout << "Jolly\n";
    }
    return 0;
}