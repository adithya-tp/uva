#include <bits/stdc++.h>
using namespace std;

/*
    If the length is 5, little brother means to say 3.
    Else, if there is a match for "on-" or "-ne" or "o-e", little brother means to say 1.
    Else he means to say 2.
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
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        if(s.size() == 5) {
            cout << "3\n";
        } else {
            if((s[0] == 'o' && s[1] == 'n') || (s[1] == 'n' && s[2] == 'e') || (s[2] == 'e' && s[0] == 'o'))
                cout << "1\n";
            else
                cout << "2\n";
        }
    }
    return 0;
}