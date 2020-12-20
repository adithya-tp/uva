#include <bits/stdc++.h>
using namespace std;

/*
    For each test case simply add up the product of the farmer's land area
    and environmental-friendliness value (because number of animals get's cancelled out).
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
    int t, f, a, b, c, sum;
    cin >> t;
    while(t--) {
        cin >> f;
        sum = 0;
        while(f--) {
            cin >> a >> b >> c;
            sum += (a * c);
        }
        cout << sum << "\n";
    }
    return 0;
}