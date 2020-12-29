#include <bits/stdc++.h>
using namespace std;

/*
    Since the boxes can be stacked in any order, we will first sort them with a custom
    comparator to fit the problem constraints. Once this is done, it turns into a 
    variant of the Longest Increasing Subsequence (LIS) problem.
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

bool compare(ii a, ii b) {
    if(a.first < b.first) return true;
    else if(a.first == b.first && a.second < b.second) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n, n) {
        vii blocks(n);
        forn(i, 0, n - 1) {
            cin >> blocks[i].first >> blocks[i].second;
        }
        sort(blocks.begin(), blocks.end(), compare);

        vi memo(n, 1);
        int max_height = 1;
        forn(i, 0, n - 1) {
            forn(j, 0, i - 1) {
                if(blocks[j].first <= blocks[i].first && blocks[j].second <= blocks[i].second) {
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
            max_height = max(max_height, memo[i]);
        }
        cout << max_height << "\n";
    }
    cout << "*\n";
    return 0;
}