#include <bits/stdc++.h>
using namespace std;

/*
    Use a tracker variable to know when to push in `` or '' 
    to the stringstream
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int x = 1;
    while(getline(cin, s)) {
        stringstream ss;
        for(char c : s) {
            if(c == '"') {
                if(x) {
                    ss << "``";
                } else {
                    ss << "''";
                }
                x ^= 1;
            } else {
                ss << c;
            }
        }
        cout << ss.str() << "\n";
    }
    return 0;
}