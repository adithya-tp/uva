#include <bits/stdc++.h>
using namespace std;

/*
    This is the most twisted way I've seen someone ask for the max of an array.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, c = 1;
    string s;
    getline(cin, s);
    t = stoi(s);
    while(t--) {
        getline(cin, s);
        int max_elem = INT_MIN;
        string word = "";
        for(char c : s) {
            word += c;
            if(isspace(c)) {
                max_elem = max(max_elem, stoi(word));
                word = "";
            }
        }
        cout << "Case " << c++ << ": " << max(max_elem, stoi(word)) << "\n";
    }
    return 0;
}