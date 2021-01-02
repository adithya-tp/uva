#include <bits/stdc++.h>
using namespace std;

/*
    Iterate through the poeple and the words as long as either one
    of the following conditions hold true:

    1. The last person hasn't sung a word yet.
    2. They are in the middle of the song.
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
    int t;
    cin >> t;
    string s;
    unordered_map<string, int> w;
    vector<string> names;
    vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    forn(i, 0, t - 1) {
        cin >> s;
        names.pb(s);
    }
    int idx = 0;
    int name_idx = 0;
    while(!w[s] || (idx % 16)) {
        w[names[name_idx]]++;
        cout << names[name_idx] << ": " << song[idx] << "\n";
        idx = (idx + 1) % 16;
        name_idx = (name_idx + 1) % t;
    }
    return 0;
}