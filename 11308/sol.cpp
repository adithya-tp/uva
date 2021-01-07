#include <bits/stdc++.h>
using namespace std;

/*
    Check if the prices of each recipe stays within the budget. 
    If so add them to a vector which will be sorted after all recipes have been 
    processed.

    If no such recipe exists, print "Too expensive!", else just print out the
    sorted vector recipe names.
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
    int b, ing, rec, bud, price, units, steps;
    cin >> b;
    while(b--) {
        string bind_name, ing_name, rec_name;
        cin >> skip_endl;
        getline(cin, bind_name);
        transform(bind_name.begin(), bind_name.end(), bind_name.begin(), ::toupper);
        cin >> ing >> rec >> bud;
        unordered_map<string, int> ing_prices;
        while(ing--) {
            cin >> ing_name;
            cin >> ing_prices[ing_name];
        }
        vector<pair<int, string>> viable;
        while(rec--) {
            price = 0;
            cin >> skip_endl;
            getline(cin, rec_name);
            cin >> steps;
            while(steps--) {
                cin >> ing_name >> units;
                price += (ing_prices[ing_name] * units);
            }
            if(price <= bud) {
                viable.pb(make_pair(price, rec_name));
            }
        }
        cout << bind_name << "\n";
        if(!viable.size()) {
            cout << "Too expensive!\n";
        } else {
            sort(viable.begin(), viable.end());
            for(auto i : viable) {
                cout << i.second << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}