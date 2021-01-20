#include <bits/stdc++.h>
using namespace std;

/*
    This is a variation of the LIS problem. Before sorting the box
    dimensions, we must population the 'boxes' vector with all possible
    permuations of each dimension, because they've got unlimited copies of each box.

    After sorting the resulting box dimensions vector, we could run the LIS algorithm
    where the DP update is only done if the preceeding boxes can be stacked.
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

bool compare(vi a, vi b) {
    if (a[0] < b[0]) return true;
    else if (a[0] == b[0] && a[1] < b[1]) return true;
    else if (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num, c = 1;
    while(cin >> num, num) {
        vvi boxes;
        forn(i, 0, num - 1) {
            vi dims(3);
            cin >> dims[0] >> dims[1] >> dims[2];
            sort(dims.begin(), dims.end());
            do {
                boxes.pb(dims);
            } while(next_permutation(dims.begin(), dims.end()));
            sort(dims.begin(), dims.end());
        }
        sort(boxes.begin(), boxes.end(), compare);
        
        vi memo(boxes.size());
        int max_height = INT_MIN;
        forn(i, 0, boxes.size() - 1) {
            max_height = max(max_height, boxes[i][2]);
            memo[i] = boxes[i][2];
        }
        
        forn(i, 1, boxes.size() - 1) {
            forn(j, 0, i - 1) {
                if(boxes[j][0] < boxes[i][0] && boxes[j][1] < boxes[i][1]) {
                    memo[i] = max(memo[i], memo[j] + boxes[i][2]);
                }
            }
            max_height = max(max_height, memo[i]);
        }
        cout << "Case " << c++ << ": maximum height = " << max_height << "\n";
    }
    return 0;
}