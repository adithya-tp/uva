#include <bits/stdc++.h>
using namespace std;

/*
    Keep crediting and debiting the debenture values from the monetary
    reserves of the corresponding banks, according to the indices 
    provided in each of the N lines. At the end of it if no banks have 
    negative reserve, then it's possible to pay all debts.
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
    int b, n, d, c, deb;
    while(cin >> b >> n, b || n) {
        bool resolved = true;
        vi mon(b);
        forn(i, 0, b - 1)
            cin >> mon[i];
        int sum = 0;
        forn(i, 0, n - 1) {
            cin >> d >> c >> deb;
            mon[d - 1] -= deb;
            mon[c - 1] += deb;
        }
        for(int i : mon) {
            if(i < 0)
                resolved = false;
        }        
        if(resolved)
            cout << "S\n";
        else
            cout << "N\n";
    }
    return 0;
}