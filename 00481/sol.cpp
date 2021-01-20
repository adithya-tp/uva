#include <bits/stdc++.h>
using namespace std;

/*
    nLogk implementation of Longest Increasing Subsequence. The logk factor comes in
    because for each of the n elements we perform binary search to check if it should
    replace some element or extend the array.
    We also maintain a parent map to print out the latest LIS.
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
    vi v;
    int n;
    while(cin >> n) {
        v.pb(n);
    }
    vi lis = {v[0]};
    vi lis_id = {0};
    unordered_map<int, int> parent;
    parent[0] = -1;
    forn(i, 1, v.size() - 1) {
        int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if(idx == lis.size()) {
            lis.pb(v[i]);
            lis_id.pb(i);
        }
        else {
            lis[idx] = v[i];
            lis_id[idx] = i;
        }
        if(!idx)
            parent[i] = -1;
        else
            parent[i] = lis_id[idx - 1];
    }
    cout << lis.size() << "\n-\n";
    vector<int> path;
    int parent_id = lis_id[lis_id.size() - 1];
    while(parent_id != -1) {
        path.pb(v[parent_id]);
        parent_id = parent[parent_id];
    }
    fornr(i, path.size() - 1, 0)
        cout << path[i] << "\n";
    return 0;
}