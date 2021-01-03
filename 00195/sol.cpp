#include <bits/stdc++.h>
using namespace std;

/*
    Generating all permutations is easy in C++ if you use the next_permutation function
    after sorting the input string (sort, otherwise you won't cover the permutations
    that come before the input string lexicographically).

    Sorting is the trickier bit. You need a custom sort function that sorts strings
    based on their place in the alphabet alone, and not their case. For example, 
    with the out-of-the-box sort function strings like ABab would come before AaBb.
    This questions requires those strings to be printed the other way around.

    Simply put if the cases of corresponding characters are different you compare
    them by their position in the alphabet, not by their ascii value.
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


bool comp(string a, string b) {
    forn(i, 0, a.size() - 1) {
        if(a[i] == b[i])
            continue;
        else if(tolower(a[i]) == tolower(b[i])) {
            if(isupper(a[i])) return true;
            else return false;
        }
        else {
            if(islower(a[i]) && isupper(b[i]) || isupper(a[i]) && islower(b[i])) return tolower(a[i]) < tolower(b[i]);
            return a[i] < b[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        vector<string> strings;
        sort(s.begin(), s.end());
        do {
            strings.pb(s);
        } while(next_permutation(s.begin(), s.end()));
        sort(strings.begin(), strings.end(), comp);
        for(auto i : strings) {
            cout << i << "\n";
        }
    }
    return 0;
}