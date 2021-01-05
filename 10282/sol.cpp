#include <bits/stdc++.h>
using namespace std;

/*
    Use a simple dictionary to keep track of translations and print out
    the corresponding translation. If the key doesn't exist print "eh".
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
    unordered_map<string, string> tr;
    while(getline(cin, s)) {
        if(!s.size()) break;
        stringstream ss(s);
        string a, b;
        ss >> a >> b;
        tr[b] = a;
    }
    while(getline(cin, s)) {
        if(tr.find(s) == tr.end()) {
            cout << "eh\n";
        } else {
            cout << tr[s] << "\n";
        }
    }

    return 0;
}