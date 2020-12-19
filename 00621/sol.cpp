#include <bits/stdc++.h>
using namespace std;

/*
    Apply a check for each of the four cases.
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
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        if(s == "1" || s == "4" || s == "78")
            cout << "+\n";
        else if(s.substr(s.size() - 2, 2) == "35")
            cout << "-\n";
        else if(s.substr(0, 3) == "190")
            cout << "?\n";
        else
            cout << "*\n";
    }
    return 0;
}