#include <bits/stdc++.h>
using namespace std;

/*
    Maintain a group for each anagram, sort each group, 
    and make pairs lexicographically, and sort these
    lexicographic pairs, lexicographically. (I'll admit I wanted this to sound confusing).
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
    int t, c = 0;
    string s;
    string sorted_s;
    cin >> t >> skip_endl;
    getline(cin, s);
    while(t--) {
        if(c)
            cout << "\n";
        c = 1;
        int idx = 0;
        unordered_map<string, int> no_space2i;
        unordered_map<int, vi> anagrams;
        vector<string> strings;
        while(getline(cin, s)) {
            if(!s.size()) break;
            strings.pb(s);
            stringstream ss(s);
            stringstream no_space;
            string word;
            while(ss >> word) {
                no_space << word;
            }
            word = no_space.str();
            sort(word.begin(), word.end());
            if(no_space2i.find(word) == no_space2i.end()) {
                no_space2i[word] = idx;
            }
            anagrams[no_space2i[word]].pb(idx++);
        }

        vector<pair<string, string>> pairs;
        for(auto i : anagrams) {
            int n = i.second.size();
            if(n > 1) {
                forn(j, 0, n - 2) {
                    forn(k, j + 1, n - 1) {
                        string s1 = strings[i.second[j]];
                        string s2 = strings[i.second[k]];
                        if(s1.compare(s2) < 0)
                            pairs.pb(make_pair(s1,s2));
                        else
                            pairs.pb(make_pair(s2, s1));
                    }
                }
            }
        }
        sort(pairs.begin(), pairs.end());

        for(auto j : pairs) {
            cout << j.first << " = " << j.second << "\n";
        }
    }
    return 0;
}