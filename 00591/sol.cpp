#include <bits/stdc++.h>
using namespace std;

/*
    Find the average height and add up the difference between the average height, 
    and height of tower i if tower i is shorter than the average.
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
    int n, c = 1;
    while(cin >> n, n) {
        vi v(n);
        int sum = 0;
        forn(i, 0, n - 1) {
            cin >> v[i];
            sum += v[i];
        }
        int avg = sum / n;
        int moves = 0;
        for(auto i : v) {
            if(i < avg) {
                moves += (avg - i);
            }
        }
        cout << "Set #" << c++ << "\n";
        cout << "The minimum number of moves is " << moves << ".\n\n";
    }
    return 0;
}