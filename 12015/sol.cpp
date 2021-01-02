#include <bits/stdc++.h>
using namespace std;

/*
    Maintain a hash map from relevance to a vector of websites with that relevance value.
    Keep track of the max releveance seen so far. At the end, simply print out the vector
    corresponding to the max relevance.
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
    int t, rel, c = 1;
    string s;
    cin >> t;
    while(t--) {
        int max_rel = INT_MIN;
        unordered_map<int, vector<string>> rel2web;
        forn(i, 0, 10 - 1) {
            cin >> s >> rel;
            max_rel = max(max_rel, rel);
            rel2web[rel].pb(s);
        }
        cout << "Case #" << c++ << ":\n";
        for(auto i : rel2web[max_rel]) {
            cout << i << "\n";
        }
    }
    return 0;
}