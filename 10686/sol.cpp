#include <bits/stdc++.h>
using namespace std;

/*
    Use a few maps to keep track of which words belong to what categories,
    and how many different words have been encountered so far in each category 
    for a certain problem description.

    The catch here is that normal words mixed in with gibberish need to be
    cleaned up and then compared with the entires in a map.
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
    int t, types, terms, type_count;
    string term, type, s, pre_s;
    cin >> t;
    while(t--) {
        cin >> types;
        vi counts(types, 0);
        unordered_map<string, set<int>> w2i;
        unordered_map<int, pair<string, int>> i2t;
        forn(i, 0, types - 1) {
            cin >> type >> terms >> type_count;
            i2t[i] = make_pair(type, type_count);
            while(terms--) {
                cin >> term;
                w2i[term].insert(i);
            }
        }
        cin >> skip_endl;
        vector<string> categories;
        set<string> included;
        while(getline(cin, pre_s)) {
            if(!pre_s.size()) break;
            vector<string> xx;
            string w = "";
            for(char c : pre_s) {
                if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                    w += c;
                } else {
                    xx.pb(w);
                    w = "";
                }
            }
            if(pre_s[pre_s.size() - 1] != ' ')
                xx.pb(w);
            for(string word : xx) {
                if(w2i.find(word) != w2i.end() && included.find(word) == included.end()) {
                    included.insert(word);
                    for(auto i : w2i[word]) {
                        counts[i]++;
                    }
                }
            }               
        }
        forn(i, 0, types - 1) {
            if(counts[i] >= i2t[i].second) {
                categories.pb(i2t[i].first);
            }
        }
        if(!categories.size()) {
            cout << "SQF Problem.\n";
        } else {
            forn(i, 0, categories.size() - 1) {
                cout << categories[i];
                if(i != categories.size() - 1)
                    cout << ",";
            }
            cout << "\n";
        } 
    }
    return 0;
}