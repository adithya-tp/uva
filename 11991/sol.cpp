#include <bits/stdc++.h>
using namespace std;

/*
    Use a hash-map where the key is each unique value, and the value
    is a vector of all 1-based indices of the unique value's appearance.

    Print the index if the n-th occurence in a query doesn't exceed the
    size of the value's vector in the query.
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
    int n, q;
    while(cin >> n >> q) {
        unordered_map<int, vi> adj;
        int num, pos;
        forn(i, 0, n - 1) {
            cin >> num;
            adj[num].pb(i + 1);
        }

        forn(i, 0, q - 1) {
            cin >> pos >> num;
            if(pos > adj[num].size()) {
                cout << "0\n";
                continue;
            } else {
                cout << adj[num][pos - 1] << "\n";
            }

        }
    }
    return 0;
}