#include <bits/stdc++.h>
using namespace std;

/*
    Maintain a pointer that stops at the next free spot that a card can be placed.
    This pointer keeps traversing the array in a cycle looking for a free spot till 
    it can find it.
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
    int n;
    string s;
    while(cin >> n, n) {
        vector<pair<string, int>> v(n);
        forn(i, 0, n - 1) {
            cin >> v[i].first;
            cin >> s;
            v[i].second = s.size();
        }
        vector<int> o(n, -1);
        int xx = 0;
        forn(i, 0, n - 1) {
            for(int j = xx, count = 0; count != v[i].second; j = (j + 1) % n) {
                if(o[j] != -1) {
                    continue;
                } else {
                    count++;
                    xx = j;
                }
            }
            while(o[xx] != -1) {
                xx = (xx + 1) % n;
            }
            o[xx] = i;
        }
        forn(i, 0, n - 1) {
            if(i)
                cout << " ";
            cout << v[o[i]].first;
        }
        cout << "\n";
    }
    return 0;
}