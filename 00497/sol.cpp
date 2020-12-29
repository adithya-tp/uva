#include <bits/stdc++.h>
using namespace std;

/*
    Longest Increasing Subsequence problem while also maintaining a 'parent map' to print
    out the resulting path.
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

void print_lis(vi& v, int lis_end_id, unordered_map<int, int>& parent) {
    if(lis_end_id == -1)
        return;        
    print_lis(v, parent[lis_end_id], parent);
    cout << v[lis_end_id] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, num, c = 0;
    string s;
    cin >> t >> skip_endl;
    getline(cin, s);
    while(t--) {
        if(c)
            cout << "\n";
        c = 1;
        vi v;
        while(getline(cin, s)) {
            if(!s.size()) break;
            else {
                v.pb(stoi(s));
            }
        }
        
        unordered_map<int, int> parent;
        vi memo(v.size(), 1);
        int max_lis = 1;
        int lis_end_id = 0;
        forn(i, 0, v.size() - 1) {
            int max_id = -1;
            forn(j, 0, i - 1) {
                if(v[j] < v[i]) {
                    if(memo[j] + 1 > memo[i]) {
                        memo[i] = memo[j] + 1;
                        max_id = j;
                    }
                }
            }
            if(memo[i] > max_lis) {
                max_lis = memo[i];
                lis_end_id = i;
            }
            parent[i] = max_id;
        }
        cout << "Max hits: " << max_lis << "\n";
        print_lis(v, lis_end_id, parent);
    }

    return 0;
}