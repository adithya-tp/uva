#include <bits/stdc++.h>
using namespace std;

/*
    An if-else is all you need
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
    int c = 1;
    while(getline(cin, s) && s != "*") {
        cout << "Case " << c << ": ";
        c++;
        if(s == "Hajj")
            cout << "Hajj-e-Akbar\n";
        else
            cout << "Hajj-e-Asghar\n";
    }
    return 0;
}