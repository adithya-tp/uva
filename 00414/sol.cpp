#include <bits/stdc++.h>
using namespace std;

/*
    The amount of space is sum of the following difference performed for each row:
    (Max_X count among all rows) - (number of Xs in row i)
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
    int n, xx;
    int total;
    while(cin >> n, n) {
        total = 0;
        vi count(n);
        int max_x = 0;
        string s;
        cin >> skip_endl;
        forn(i, 0, n - 1) {
            xx = 0;
            getline(cin, s);
            for(char c : s) {
                if(c == 'X')
                    xx++;
            }
            max_x = max(max_x, xx);
            count[i] = xx;
        }
        for(auto i : count)
            total += (max_x - i);
        cout << total << "\n";
    }
    return 0;
}