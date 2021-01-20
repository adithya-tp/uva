#include <bits/stdc++.h>
using namespace std;

/*
    Use a hash map to maintain frequencies, and a "set + vector" duo to keep track
    of the order to print each frequency.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
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
    unordered_map<int, int> f;
    int n;
    vi nums;
    set<int> x;
    while(cin >> n) {
        f[n]++;
        if(x.find(n) == x.end()) {
            x.insert(n);
            nums.pb(n);
        }
    }
    forn(i, 0, nums.size() - 1) {
        cout << nums[i] << " " << f[nums[i]] << "\n";
    }
    return 0;
}