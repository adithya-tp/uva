#include <bits/stdc++.h>
using namespace std;

/*
    Keep track of frequencies of sorted lowercase input words, and also
    keep track of what the original input was for this sorted lowercase word.
    (So that we can print the word in the same form it was input).

    Only print the words that occur once after sorting and converting to lowercase.
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
    unordered_map<string, int> f;
    unordered_map<string, string> s2s;
    while(cin >> s, s != "#") {
        string cpy = s;
        transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);
        sort(cpy.begin(), cpy.end());
        s2s[cpy] = s;
        f[cpy]++;
    }

    vector<string> strings;
    for(auto i : s2s) {
        if(f[i.first] == 1)
            strings.pb(s2s[i.first]);
    }
    sort(strings.begin(), strings.end());
    for(auto i : strings) {
        cout << i << "\n";
    }
    return 0;
}