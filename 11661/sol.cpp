#include <bits/stdc++.h>
using namespace std;

/*
    Keep two pointers between to keep track of the distance between 
    the nearest 'D' / 'R' characters. If you encounter a 'Z' during this
    process, break, and print out 0.
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
        cin >> s;
        int i = 0;
        while(s[i] == '.') i++;
        int min_d = INT_MAX;
        char curr = s[i];
        int curr_i = i;
        while(i < n) {
            if(s[i] == 'Z') {
                min_d = 0;
                break;
            }
            while((s[curr_i] == curr || s[curr_i] == '.') && curr_i < n) {
                if(s[curr_i] == curr)
                    i = curr_i;
                curr_i++;
            }
            
            if(curr_i < n) {
                min_d = min(min_d, curr_i - i);
            }
            curr = s[curr_i];
            i = curr_i;
        }
        cout << min_d << "\n";
    }

    return 0;
}