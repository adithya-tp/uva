#include <bits/stdc++.h>
using namespace std;

/*
    Having a string of length 26 with the soundex coding of each alphabet
    is a neat way to arrive at the soudex encoding of the entire word.

    Once you have this, you need to keep appending the soundex encodings
    as long as they are not spaces and the mapping for the current letter
    is not the same as the one for the previous.
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
    string lookup = " 123 12  22455 12623 1 2 2";
    string s;
    char curr;
    while(cin >> s) {
        stringstream ss;
        curr = lookup[s[0] - 'A'];
        if(curr != ' ')
            ss << curr;
        forn(i, 1, s.size() - 1) {
            curr = lookup[s[i] - 'A'];
            if(curr != lookup[s[i - 1] - 'A'] && curr != ' ') {
                ss << curr;
            } else {
                continue;
            }
        }
        cout << ss.str() << "\n";
    }
    return 0;
}