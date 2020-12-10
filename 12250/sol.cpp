#include <bits/stdc++.h>
using namespace std;

/*
    Simple dictionary lookup
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
    unordered_map<string, string> lang = {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"}, 
        {"HALLO", "GERMAN"}, 
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}
    };
    int c = 1;
    while(getline(cin, s)) {
        if(s[0] != '#') {
            cout << "Case " << c << ": ";
            if(lang.find(s) != lang.end())
                cout << lang[s] << "\n";
            else
                cout << "UNKNOWN\n";
            c++;
        }
    }
    return 0;
}