#include <bits/stdc++.h>
using namespace std;

/*
    A variation of subset sum, where we check if there exists a subset of
    elements that sums up to half of the sum of all elements in the set.
    
    If there is such a set, then automatically this means the remaining
    elements sum to the same amount (half), provided the total sum was even
    to begin with. In our problem, this means that there is indeed a way
    to load up the luggage such that both cars carry the same weight.
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
    int t;
    cin >> t >> skip_endl;
    while(t--) {
        getline(cin, s);
        stringstream ss(s);
        int num, sum = 0;
        vi v;
        while(ss >> num) {
            sum += num;
            v.pb(num);
        }
        if(sum % 2) {
            cout << "NO\n";
            continue;
        } else {
            bool t[v.size() + 1][sum / 2 + 1];
            memset(t, false, sizeof t);
            forn(i, 0, v.size()) {
                t[i][0] = true;
            }
            forn(i, 1, v.size()) {
                forn(j, 1, sum / 2) {
                    if(v[i - 1] <= j) {
                        t[i][j] = t[i - 1][j] ||  t[i - 1][j - v[i - 1]];
                    } else {
                        t[i][j] = t[i - 1][j];
                    }
                }
            }
            if(t[v.size()][sum / 2])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}