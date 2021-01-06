#include <bits/stdc++.h>
using namespace std;

/*
    Keep a hash map of word, value pairs and add up the values for 
    each description.
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
    int m, n, val;
    string word;
    unordered_map<string, int> w2val;
    cin >> m >> n;
    while(m--) {
        cin >> word >> val;
        w2val[word] = val;
    }
    cin >> skip_endl;
    while(n--) {
        int val = 0;
        while(getline(cin, word)) {
            if(word == ".") break;
            stringstream ss(word);
            string curr_word;
            while(ss >> curr_word)
                val += w2val[curr_word];
        }
        cout << val << "\n";
    }
    return 0;
}