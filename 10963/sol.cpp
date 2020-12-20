#include <bits/stdc++.h>
using namespace std;

/*
    As long as the gap for each column stays constant, the 
    two blocks can be merged.
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
    int t, cols, r1, r2, c = 0;
    cin >> t;
    while(t--) {
        if(c)
            cout << "\n";
        cin >> cols;
        bool perfect = true;
        cin >> r1 >> r2;
        int curr = abs(r1 - r2);
        forn(i, 0, cols - 2) {
            cin >> r1 >> r2;
            if(abs(r1 - r2) != curr)
                perfect = false;
        }
        if(perfect)
            cout << "yes\n";
        else
            cout << "no\n";
        c++;
    }
    return 0;
}