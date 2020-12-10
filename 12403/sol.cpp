#include <bits/stdc++.h>
using namespace std;

/*
    Keep and global variable to track donations so far, report as necessary.
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
    int t, m;
    string s;
    cin >> t;
    int money = 0;
    while(t--) {
        cin >> s;
        if(s == "report")
            cout << money << "\n";
        else {
            cin >> m;
            money += m;
        }
    }
    return 0;
}