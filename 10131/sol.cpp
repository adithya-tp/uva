#include <bits/stdc++.h>
using namespace std;

/*
    A variation of the longest increasing subsequence (LIS) problem. 
    
    After sorting (which needs to be a custom sort), the dynamic programming implementation of LIS for this problem
    is pretty much the same as a vanilla LIS implementation.
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

bool compare(pair<ii, int> a, pair<ii, int> b) {
    if(a.first.first < b.first.first) return true;
    if(a.first.first == b.first.first && a.first.second > b.first.second) return true;
    return false;
}

void print_lis(vector<pair<ii, int>>& v, unordered_map<int, int>& p, int lis_end) {
    if(lis_end == -1) {
        return;
    }
    print_lis(v, p, p[lis_end]);
    cout << v[lis_end].second << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, w;
    vector<pair<ii, int>> pairs;
    int idx = 1;
    while(cin >> w >> q) {
        pairs.pb(make_pair(make_pair(w, q), idx++));
        sort(pairs.begin(), pairs.end(), compare);
    }

    int l = pairs.size();
    vi memo(l, 1);
    unordered_map<int, int> p;
    int max_len = 1, lis_end = 0;
    forn(i, 0, l - 1) {
        int max_id = -1;
        forn(j, 0, i - 1) {
            if(pairs[i].first.first > pairs[j].first.first && pairs[i].first.second < pairs[j].first.second) {
                if(memo[j] + 1 > memo[i]) {
                    memo[i] = memo[j] + 1;
                    max_id = j;
                }
            }
        }
        p[i] = max_id;
        if(memo[i] > max_len) {
            max_len = memo[i];
            lis_end = i;
        }
    }
    cout << max_len << "\n";
    print_lis(pairs, p, lis_end);
    return 0;
}