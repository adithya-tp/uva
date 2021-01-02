#include <bits/stdc++.h>
using namespace std;

/*
    We cumulate the amounts for each duration according to each provider's
    rates using int((duration / rate_window) + 1) * rate_per_rate_window.

    Compare these values and print the appropriate message.
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
    int t, durations, duration, c = 1;
    cin >> t;
    while(t--) {
        cin >> durations;
        int m = 0, j = 0;
        forn(i, 0, durations - 1) {
            cin >> duration;
            m += (int((duration + 30) / 30) * 10);
            j += (int((duration + 60) / 60) * 15);
        }
        cout << "Case " << c++ << ": ";
        if(m > j) {
            cout << "Juice " << j << "\n";
        } else if(m < j) {
            cout << "Mile " << m << "\n";
        } else {
            cout << "Mile Juice " << m << "\n";
        }
    }
    return 0;
}